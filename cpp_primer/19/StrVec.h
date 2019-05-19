#ifndef __STRVEC_H__
#define __STRVEC_H__

#include <string>
#include <memory>
#include <initializer_list>
#include <algorithm>

using std::initializer_list;
using std::string;

class StrVec
{
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec(initializer_list<string> il);
    ~StrVec() { free(); }
    StrVec &operator=(const StrVec&);
    StrVec &operator=(StrVec&&) noexcept;
    string &operator[](size_t pos) const;
    void push_back(const string&);
    void push_back(string&&); 
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t n);
    void resize(size_t n);
    string *begin() const { return elements; }
    string *end() const { return first_free; }

private:
    std::allocator<string> alloc;
    void chk_n_alloc()  { if (size() == capacity()) reallocate(); }
    std::pair<string*, string*> alloc_n_copy
        (const string*, const string*);
    void alloc_n_move(size_t n);
    void free();
    void free2();  // use for_each and lambda
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};

StrVec::StrVec(const StrVec& sv)
{
    auto mem = alloc_n_copy(sv.begin(), sv.end());
    elements = mem.first;
    cap = first_free = mem.second;
}

StrVec::StrVec(StrVec &&sv) noexcept :
    elements(sv.elements), first_free(sv.first_free), cap(sv.cap)
{
    sv.elements = sv.first_free = sv.cap = nullptr;
}

StrVec::StrVec(initializer_list<string> il)
{
    auto mem = alloc_n_copy(il.begin(), il.end());
    elements = mem.first;
    cap = first_free = mem.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.cap = rhs.first_free = rhs.elements = nullptr;
        return *this;
    }
}

string& StrVec::operator[](size_t pos) const
{
    return *(elements + pos);
}

void StrVec::push_back(const string& str)
{
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

void StrVec::push_back(string&& str)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(str));
}

void StrVec::reserve(size_t n)
{
    if (n > capacity())
    {
        alloc_n_move(n);
    }
}

void StrVec::resize(size_t n)
{
    reserve(n);

    if (n > size())
    {
        uninitialized_fill(first_free, elements + n, string());
        first_free = elements + n;
    }
    else if (n < size())
    {
        for (auto last = elements + n; first_free != last; )
            alloc.destroy(--first_free);
    }
}

std::pair<string*, string*> StrVec::alloc_n_copy
    (const string* beg, const string* end)
{
    auto data = alloc.allocate(end - beg);
    return {data, uninitialized_copy(beg, end, data)};
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
        elements = first_free = cap = nullptr;
    }
}

void StrVec::free2()
{
    if (elements)
    {
        for_each(elements, first_free, [this](string &s) { alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
        elements = first_free = cap = nullptr;
    }
}

void StrVec::reallocate()
{
    auto new_cap = size() ? 2 * size() : 1;
    alloc_n_move(new_cap);
}

#endif

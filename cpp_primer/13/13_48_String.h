#ifndef __STRING_H__
#define __STRING_H__

#include <memory>
#include <cstring>
#include <iostream>

using std::allocator;
using std::ostream;
using std::istream;

class String
{
friend istream &operator>>(istream &input, String &str);
public:
    String(): elem(nullptr), unused(nullptr), cap(nullptr) { }
    String(const char *pc);
    String(const String &s);
    String(int num, const char &ch);
    ~String() { free(); }
    String &operator=(const String &s);
    char &operator[](size_t pos) const { return *(elem + pos); }
    String &operator+=(const char *pc);
    String &operator+=(const String &pc);

    void push_back(const char &c);
    size_t size() const { return unused - elem; }
    size_t capacity() const { return cap - elem; }
    void reserve(size_t len);
    void resize(size_t len);
    char *begin() const { return elem; }
    char *end() const { return unused; }
private:
    allocator<char> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<char *, char *> alloc_n_copy(const char*, const char*);
    void alloc_n_move(size_t n);
    void free();
    void reallocate();
    char *elem;
    char *unused;
    char *cap;
};

String::String(const char *pc)
{
    std::cout << "String(const char *pc)" << std::endl;
    auto mem = alloc_n_copy(pc, pc + strlen(pc));
    elem = mem.first;
    cap = unused = mem.second;
}

String::String(const String &str)
{
    std::cout << "String(const String &str)" << std::endl;
    auto mem = alloc_n_copy(str.begin(), str.end());
    elem = mem.first;
    cap = unused = mem.second;
}

String::String(int num, const char &ch)
{
    elem = alloc.allocate(num);
    cap = unused = elem + num;
    std::uninitialized_fill(elem, unused, ch);
}

String& String::operator=(const String &str)
{
    std::cout << "operator=(const String &str)" << std::endl;
    auto mem = alloc_n_copy(str.begin(), str.end());
    free();
    elem = mem.first;
    cap = unused = mem.second;
}

String &String::operator+=(const char *pc)
{
    size_t len = strlen(pc);
    if (size() + len > capacity())
    {
        alloc_n_move(size() + len);
    }

    std::uninitialized_copy(pc, pc + len, unused);
    unused += len;

    return *this;
}

String &String::operator+=(const String &str)
{
    if (size() + str.size() > capacity())
    {
        alloc_n_move(size() + str.size());
    }

    std::uninitialized_copy(str.begin(), str.end(), unused);
    unused += str.size();

    return *this;
}

ostream &operator<<(ostream &output, const String &str)
{
    for (auto beg = str.begin(); beg != str.end(); ++beg)
        output << *beg;

    return output;
}

istream &operator>>(istream &input, String &str)
{
    str.free();

    char ch;
    while (input.get(ch) && ch != '\n')
        str.push_back(ch);

    return input;
}

void String::reserve(size_t len)
{
    if (len > capacity())
        alloc_n_move(len);
}

void String::resize(size_t len)
{
    if (len > capacity())
    {
        alloc_n_move(len);
        std::uninitialized_fill(unused, cap, 0);
    }
    else if (len > size())
    {
        std::uninitialized_fill(unused, elem + len, 0);
        unused = elem + len;
    }
    else
    {
        for (auto last = elem + len; last != unused; )
            alloc.destroy(--unused);
    }
}

void String::push_back(const char &c)
{
    chk_n_alloc();
    alloc.construct(unused++, c);
}

void String::free()
{
    if (elem)
    {
        for (char *cur = unused; cur != elem; )
            alloc.destroy(--cur);
        alloc.deallocate(elem, capacity());
        elem = unused = cap = nullptr;
    }
}

std::pair<char *, char *> String::alloc_n_copy(const char *beg, const char *end)
{
    auto new_elem = alloc.allocate(end - beg);
    return {new_elem, std::uninitialized_copy(beg, end, new_elem)};
}

void String::alloc_n_move(size_t len)
{
    auto new_elem = alloc.allocate(len);
    auto dest = new_elem;
    auto src = elem;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*src++));
    free();

    elem = new_elem;
    unused = dest;
    cap = elem + len;
}

void String::reallocate()
{
    size_t new_cap = capacity() ? 2 * capacity() : 1;
    alloc_n_move(new_cap);
}

#endif

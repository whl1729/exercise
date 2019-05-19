#ifndef __VEC_H__
#define __VEC_H__

#include <memory>
#include <initializer_list>

using std::initializer_list;

template <typename T>
class Vec
{
public:
    Vec(): elem(nullptr), unused(nullptr), cap(nullptr) { }
    Vec(const Vec &v);
    Vec(Vec &&v) noexcept;
    Vec(initializer_list<T> il);
    ~Vec() { free(); }
    Vec &operator=(const Vec &v);
    Vec &operator=(Vec &&v) noexcept;
    T &operator[](size_t pos) { return *(elem + pos); }
    void push_back(const T &t);
    void push_back(T &&t);
    size_t size() const { return unused - elem; }
    size_t capacity() const { return cap - elem; }
    void reserve(size_t n);
    void resize(size_t n);
    T *begin() const { return elem; }
    T *end() const { return unused; }
    template <typename... Args> void emplace_back(Args&&... args);

private:
    std::allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void alloc_n_move(size_t n);
    void free();
    void reallocate();
    T *elem;
    T *unused;
    T *cap;
};

template <typename T>
Vec<T>::Vec(const Vec<T> &v)
{
    auto mem = alloc_n_copy(v.cbegin(), v.cend());
    elem = mem.first;
    cap = unused = mem.sceond;
}

template <typename T>
Vec<T>::Vec(Vec<T> &&v) noexcept:
    elem(v.elem), unused(v.unused), cap(v.cap)
{
    v.elem = v.unused = v.cap = nullptr;
}

template <typename T>
Vec<T>::Vec(initializer_list<T> il)
{
    auto mem = alloc_n_copy(il.begin(), il.end());
    elem = mem.first;
    cap = unused = mem.second;
}

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    auto l = lhs.begin(), r = rhs.begin();
    for (size_t i = 0; i < lhs.size(); ++i)
        if (l[i] != r[i])
            return false;

    return true;
}

template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
    size_t len = lhs.size() < rhs.size() ? lhs.size() : rhs.size();

    for (size_t pos = 0; pos < len; ++pos)
    {
        if (lhs[pos] < rhs[pos])
            return true;
        else if (lhs[pos] > rhs[pos])
            return false;
    }

    return (lhs.size() < rhs.size() ? true : false);
}

template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
    size_t len = lhs.size() < rhs.size() ? lhs.size() : rhs.size();

    for (size_t pos = 0; pos < len; ++pos)
    {
        if (lhs[pos] > rhs[pos])
            return true;
        else if (lhs[pos] < rhs[pos])
            return false;
    }

    return (lhs.size() > rhs.size() ? true : false);
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elem = data.first;
    unused = cap = data.second;
    return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec<T> &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elem = rhs.elem;
        unused = rhs.unused;
        cap = rhs.cap;
        rhs.cap = rhs.unused = rhs.elem = nullptr;
        return *this;
    }
}

template <typename T>
void Vec<T>::push_back(const T& t)
{
    chk_n_alloc();
    alloc.construct(unused++, t);
}

template <typename T>
void Vec<T>::push_back(T&& t)
{
    chk_n_alloc();
    alloc.construct(unused++, std::move(t));
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
    if (n > capacity())
    {
        alloc_n_move(n);
    }
}

template <typename T>
void Vec<T>::resize(size_t n)
{
    reserve(n);

    if (n > size())
    {
        uninitialized_fill(unused, elem + n, T());
        unused = elem + n;
    }
    else if (n < size())
    {
        for (auto last = elem + n; unused != last; )
            alloc.destroy(--unused);
    }
}

template <typename T>
template <typename... Args>
inline void Vec<T>::emplace_back(Args&&... args)
{
    chk_n_alloc();
    alloc.construct(unused++, std::forward<Args>(args)...);
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy
    (const T* beg, const T* end)
{
    auto data = alloc.allocate(end - beg);
    return {data, uninitialized_copy(beg, end, data)};
}

template <typename T>
void Vec<T>::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto src = elem;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*src++));
    free();

    elem = newdata;
    unused = dest;
    cap = elem + new_cap;
}

template <typename T>
void Vec<T>::free()
{
    if (elem)
    {
        for (auto p = unused; p != elem; )
            alloc.destroy(--p);
        alloc.deallocate(elem, cap - elem);
        elem = unused = cap = nullptr;
    }
}

template <typename T>
void Vec<T>::reallocate()
{
    auto new_cap = size() ? 2 * size() : 1;
    alloc_n_move(new_cap);
}

#endif

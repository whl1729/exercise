#ifndef __BLOB_H__
#define __BLOB_H__

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <stdexcept>

using std::initializer_list;
using std::make_shared;
using std::ostream;
using std::size_t;
using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;

template <typename T> class Blob;
template <typename T> class BlobPtr;
template <typename T> ostream& operator<<(ostream &os, const Blob<T> &blob);

template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend ostream& operator<<<T>(ostream &os, const Blob &blob);
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;

    Blob();
    Blob(initializer_list<T> il);
    template <typename It> Blob(It b, It e);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& front();
    T& back();
    BlobPtr<T> begin() const;
    BlobPtr<T> end() const;
    T& operator[](size_type i);
private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg) const;
};

template <typename T>
    bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T>
    bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
class BlobPtr
{
    friend bool operator!=<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator==<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> b, size_t sz = 0): wptr(b.data), curr(sz) { }
    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr& operator++(int);
    BlobPtr& operator--(int);
private:
   shared_ptr<vector<T>> check(size_t, const string &) const;
   weak_ptr<vector<T>> wptr;
   size_t curr;
};

template <typename T>
Blob<T>::Blob(): data(make_shared<vector<T>>()) { }

template <typename T>
Blob<T>::Blob(initializer_list<T> il): data(make_shared<vector<T>>(il)) { }

template <typename T>
template <typename It> 
Blob<T>::Blob(It b, It e): data(make_shared<vector<T>>(b, e)) { }

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
BlobPtr<T> Blob<T>::begin() const
{
    return BlobPtr<T>(*this, 0);
}

template <typename T>
BlobPtr<T> Blob<T>::end() const
{
    return BlobPtr<T>(*this, size());
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
ostream& operator<<(ostream &os, const Blob<T> &blob)
{
    for (auto &b : blob)
        os << b << " ";

    return os;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    // TODO: the following check for equality isn't enough.
    return (lhs.curr == rhs.curr);
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "++ past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "-- past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t pos, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbounded BlobPtr");
    if (pos > ret->size())
        throw std::out_of_range(msg);
    return ret;
}

#endif

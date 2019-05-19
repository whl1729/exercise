#ifndef __STRBLOB_H__
#define __STRBLOB_H__

#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
friend class StrBlobPtr;
friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);

public:
    typedef vector<string>::size_type size_type;

    StrBlob(): data(make_shared<vector<string>>()) { }
    StrBlob(initializer_list<string> il): 
            data(make_shared<vector<string>>(il)) { }
    StrBlob(const StrBlob &b);
    StrBlob& operator=(const StrBlob &b);
    string& operator[](size_type i) { return (*data)[i]; }
    const string& operator[](size_type i) const { return (*data)[i]; }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &s) { data->push_back(s); }
    void push_back(string &&s) { data->push_back(std::move(s)); }
    void pop_back();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;
    StrBlobPtr begin() const;
    StrBlobPtr end() const;
    ostream& print(ostream &output) const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

class StrBlobPtr
{
friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz)  { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz)  { }
    string& deref() const;
    StrBlobPtr& incr();
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    string& operator[](size_t i);
    const string& operator[](size_t i) const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr operator+=(size_t i);
    StrBlobPtr operator+(size_t i);
    StrBlobPtr operator-=(size_t i);
    StrBlobPtr operator-(size_t i);
    string& operator*() const;
    string* operator->() const;

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlob::StrBlob(const StrBlob &rhb)
{
    data = make_shared<vector<string>>();

    for (auto beg = rhb.begin(), end = rhb.end(); beg != end; beg.incr())
    {
        push_back(beg.deref());
    }
}

StrBlob& StrBlob::operator=(const StrBlob &rhb)
{
    data = make_shared<vector<string>>();

    for (auto beg = rhb.begin(), end = rhb.end(); beg != end; beg.incr())
    {
        push_back(beg.deref());
    }

    return *this;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data > *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

StrBlobPtr StrBlob::begin() const
{ 
    return StrBlobPtr(*this); 
}

StrBlobPtr StrBlob::end() const
{ 
    auto ret = StrBlobPtr(*this, data->size()); 
    return ret; 
}

ostream& StrBlob::print(ostream &output) const
{
    for (auto s : *data)
        output << s << ' ';
    output << std::endl;

    return output;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto a = lhs.wptr.lock(), b = rhs.wptr.lock();
    if (!a || !b)
        throw runtime_error("weak_ptr expired");
    return ((*a == *b) && (lhs.curr == rhs.curr));
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto a = lhs.wptr.lock(), b = rhs.wptr.lock();
    if (!a || !b)
        throw runtime_error("weak_ptr expired");
    return *a < *b;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto a = lhs.wptr.lock(), b = rhs.wptr.lock();
    if (!a || !b)
        throw runtime_error("weak_ptr expired");
    return *a > *b;
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator+=(size_t i)
{
    check(curr + i, "+= out of range");
    curr += i;
    return *this;
}

StrBlobPtr StrBlobPtr::operator-=(size_t i)
{
    check(curr - i, "-= out of range");
    curr -= i;
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t i)
{
    StrBlobPtr ret = *this;
    ret += i;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t i)
{
    StrBlobPtr ret = *this;
    ret -= i;
    return ret;
}

string& StrBlobPtr::operator[](size_t i)
{
    auto p = check(i, "subscript pass end");
    return (*p)[i];
}

const string& StrBlobPtr::operator[](size_t i) const
{
    auto p = check(i, "const subscript past end");
    return (*p)[i];
}

string& StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference pass end");
    return (*p)[curr];
}

string* StrBlobPtr::operator->() const
{
    return & this->operator*();
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment pass end");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbounded StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

#endif

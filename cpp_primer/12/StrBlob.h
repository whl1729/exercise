#ifndef __STRBLOB_H__
#define __STRBLOB_H__

#include "memory"
#include "vector"
#include "string"
#include "stdexcept"

using namespace std;

class StrBlobPtr;

class StrBlob
{
friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;

    StrBlob(): data(make_shared<vector<string>>()) { }
    StrBlob(initializer_list<string> il): 
            data(make_shared<vector<string>>(il)) { }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &s) { data->push_back(s); }
    void pop_back();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;
    StrBlobPtr begin() const;
    StrBlobPtr end() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz)  { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz)  { }
    string& deref() const;
    StrBlobPtr& incr();
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }

private:
    shared_ptr<vector<string>> check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

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

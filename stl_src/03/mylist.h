#ifndef __MYLIST_H__
#define __MYLIST_H__

#include <iostream>

template <typename T> class List;

template <typename T>
class ListItem
{
    friend class List<T>;
public:
    ListItem(): _next(nullptr) {}
    ListItem(const T &val, ListItem *next = nullptr): _value(val), _next(next) {}
    T value() const { return _value; }
    ListItem* next() const { return _next; }
private:
    T _value;
    ListItem* _next;
};

template <typename T>
class List
{
public:
    List(): _front(new ListItem<T>()), _end(new ListItem<T>()), _size(0) {}
    void insert_front(T value); 
    void insert_end(T value);
    void display(std::ostream &os = std::cout) const;
    ListItem<T>* front() const { return _front; }
private:
    ListItem<T>* _end;
    ListItem<T>* _front;
    long _size;
};

template <typename T>
void List<T>::insert_front(T value)
{
    ListItem<T> *item = new ListItem<T>(value, _front->_next);
    _front->_next = item;
    if (item->_next == nullptr)
        item->_next = _end;
    ++_size;
}

template <typename T>
void List<T>::insert_end(T value)
{
    ListItem<T> *item = new ListItem<T>(value, _end);
    ListItem<T> *cur;
    for (cur = _front; cur && (cur->_next != _end); cur = cur->_next)
        ;
    cur->_next = item;
    ++_size;
}

template <typename T>
void List<T>::display(std::ostream &os) const
//void List<T>::display(std::ostream &os = std::cout) const
{
    for (auto item = _front->_next; item != _end; item = item->_next)
        os << item->_value << " ";
    os << std::endl;
}

template <typename T>
bool operator==(const ListItem<T> &item, const T &n)
{
    return item.value() == n; 
}

template <typename T>
bool operator!=(const ListItem<T> &item, const T &n)
{
    return !(operator==(item, n));
}
#endif

#ifndef __MYLIST_ITER_H__
#define __MYLIST_ITER_H__

template <class Item>
struct ListIter: public std::iterator<std::forward_iterator_tag, Item>
{
    Item *ptr;

    ListIter(Item *p = 0): ptr(p) {}

    Item &operator*() const { return *ptr; }
    Item *operator->() const { return ptr; }

    ListIter &operator++()
    {
        ptr = ptr->next();
        return *this;
    }

    ListIter operator++(int)
    {
        ListIter tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator==(const ListIter &i) const { return ptr == i.ptr; }
    bool operator!=(const ListIter &i) const { return ptr != i.ptr; }
};

#endif

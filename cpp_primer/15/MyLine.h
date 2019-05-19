#ifndef __LINE_H__
#define __LINE_H__

#include <set>
#include <memory>
#include <utility>

using std::set;
using std::shared_ptr;
using std::make_shared;
using std::pair;

using Iset = set<int>;

struct Line
{
    Line(int n = 0): num(n), lines(make_shared<Iset>()) { }
    Line(int n, shared_ptr<Iset> l): num(n), lines(shared_ptr<Iset>(l)) { }
    Line(const Line &l): num(l.num), lines(shared_ptr<Iset>(l.lines)) { }

    Line operator~() const;
    Line& operator=(const Line &rhs);
    Line& operator|=(const Line &rhs);
    Line& operator&=(const Line &rhs);

    int size() const { return lines->size(); }
    Iset::iterator begin()  const { return lines->begin(); }
    Iset::iterator end()  const { return lines->end(); }
    pair<Iset::iterator, bool> insert(int num) { return lines->insert(num); }
    Iset::iterator find(int target) const { return lines->find(target); }

    int num = 0;
    shared_ptr<Iset> lines;
};

Line operator|(const Line &lhs, const Line &rhs);
Line operator&(const Line &lhs, const Line &rhs);

#endif

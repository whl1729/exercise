#include "MyLine.h"

Line Line::operator~() const
{
    Line result(num);
    for (int pos = 0; pos < num; ++pos)
        if (find(pos) == end())
            result.insert(pos);

    return result;
}

Line& Line::operator=(const Line &rhs)
{
    lines = shared_ptr<Iset>(rhs.lines);
    num = rhs.num;
}

Line& Line::operator|=(const Line &rhs)
{
    for (auto i : rhs)
        insert(i);

    return *this;
}

Line& Line::operator&=(const Line &rhs)
{
    Line tmp(*this);
    lines = make_shared<Iset>();
    for (auto i : tmp)
        if (rhs.find(i) != rhs.end())
            insert(i);

    return *this;
}

Line operator|(const Line &lhs, const Line &rhs)
{
    Line result(lhs);
    result |= rhs;
    return result;
}

Line operator&(const Line &lhs, const Line &rhs)
{
    Line result(lhs);
    result &= rhs;
    return result;
}

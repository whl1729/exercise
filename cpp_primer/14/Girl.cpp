#include "Girl.h"

ostream& operator<<(ostream &output, const Girl &g)
{
    output << g.name << ": " << g.age << " years old, " << g.height << " cm.";
    return output;
}

istream& operator>>(istream &input, Girl &g)
{
    input >> g.name >> g.age >> g.height;
    if (!input)
        g = Girl();
    return input;
}

bool operator==(const Girl &lhs, const Girl &rhs)
{
    return (lhs.name == rhs.name && lhs.age == rhs.age);
}

bool operator!=(const Girl &lhs, const Girl &rhs)
{
    return !(lhs == rhs);
}

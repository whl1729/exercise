#include <iostream>
#include "Person.h"

using namespace std;

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.addr;
    return is;
}

ostream &print(ostream &os, Person &person)
{
    os << person.name << " " << person.addr;
    return os;
}

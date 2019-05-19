#ifndef __PERSON_H__
#define __PERSON_H__

using std::string;
using std::istream;
using std::ostream;
using std::cin;

struct Person
{
public:
    Person() = default;
    Person(const string &n, const string &a): name(n), addr(a) { }
    Person(istream &is) { is >> name >> addr; }
    string get_name() const { return name; }
    string get_addr() const { return addr; }

private:
    string name;
    string addr;

friend istream &read(istream &is, Person &person);
friend ostream &print(ostream &os, Person &person);
};

istream &read(istream &is, Person &person);
ostream &print(ostream &os, Person &person);

#endif

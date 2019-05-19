#ifndef __GIRL_H__
#define __GIRL_H__

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Girl
{
friend ostream& operator<<(ostream &output, const Girl &g);
friend istream& operator>>(istream &input, Girl &g);
friend bool operator==(const Girl &lhs, const Girl &rhs);
friend bool operator!=(const Girl &lhs, const Girl &rhs);

public:
    Girl(): name("Lucy"), age(18), height(170) { }
    Girl(const string &n, int a, int h): name(n), age(a), height(h) { }
    explicit operator bool() const { return name != string(); }
private:
    string name;
    int age;
    int height;
};

ostream& operator<<(ostream &output, const Girl &g);
istream& operator>>(istream &input, Girl &g);
bool operator==(const Girl &lhs, const Girl &rhs);
bool operator!=(const Girl &lhs, const Girl &rhs);

#endif

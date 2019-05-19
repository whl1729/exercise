#ifndef __FOO_H__
#define __FOO_H__

#include <algorithm>
#include <vector>

using namespace std;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "&&" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "&" << endl;
    Foo ret(*this);
    return ret.sorted();
}

#endif

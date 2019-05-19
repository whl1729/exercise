#include <iostream>
#include <vector>

using namespace std;

class NoDefault
{
public:
    NoDefault(int ci) {}
};

class C
{
public:
    C() : ndf(0) {}

private:
    NoDefault ndf;
};

int main()
{
    C cat;

    vector<C> vc(10);
    vector<NoDefault> vn(10);

    return 0;
}

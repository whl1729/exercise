#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<string> p1(new string("hello world"));
    unique_ptr<string> p2(p1);
    unique_ptr<string> p3 = p2;

    return 0;
}

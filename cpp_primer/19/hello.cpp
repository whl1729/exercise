#include <iostream>

using namespace std;

int main()
{
    string *sp = new string("hello world");
    cout << *sp << endl;
    sp->~string();
    new (sp) string("hello tomorrow");
    cout << *sp << endl;

    return 0;
}

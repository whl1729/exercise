#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    Person alice;
    Person bob("Bob", "Guangzhou");
    Person candy(cin);

    print(cout, alice) << endl;
    print(cout, bob) << endl;
    print(cout, candy) << endl;

    return 0;
}

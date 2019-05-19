#include <iostream>
#include "Query.h"
#include "AndQuery.h"
#include "NotQuery.h"

using namespace std;

int main()
{
    Query_base *pb = new AndQuery();
    Query_base *pc = new NotQuery();
    AndQuery aq;
    
    cout << "pb points to " << typeid(*pb).name() << endl;
    cout << "pc points to " << typeid(*pc).name() << endl;
    cout << "typeid(aq) is " << typeid(aq).name() << endl;

    if (typeid(*pb) == typeid(*pc))
        cout << "typeid(*pb) == typeid(*pc)" << endl;
    else
        cout << "typeid(*pb) != typeid(*pc)" << endl;

    if (typeid(*pb) == typeid(aq))
        cout << "typeid(*pb) == typeid(aq)" << endl;
    else
        cout << "typeid(*pb) != typeid(aq)" << endl;

    if (typeid(*pc) == typeid(aq))
        cout << "typeid(*pc) == typeid(aq)" << endl;
    else
        cout << "typeid(*pc) != typeid(aq)" << endl;

    delete pb;
    delete pc;

    return 0;
}

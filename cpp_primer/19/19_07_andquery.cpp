#include <iostream>
#include "Query.h"
#include "AndQuery.h"
#include "NotQuery.h"

using namespace std;

int main()
{
    AndQuery aq;
    Query_base &rb = aq;

    cout << "typeid(rb) is " << typeid(rb).name() << endl;

    try
    {
        AndQuery &ra = dynamic_cast<AndQuery&>(rb);
        cout << "cast Query_base to AndQuery succeed" << endl;
    }
    catch (bad_cast)
    {
        cout << "cast Query_base to AndQuery failed" << endl;
    }

    NotQuery nq;
    Query_base &rc = nq;
    cout << "typeid(rc) is " << typeid(rc).name() << endl;

    try
    {
        AndQuery &ra = dynamic_cast<AndQuery&>(rc);
        cout << "cast Query_base to AndQuery succeed" << endl;
    }
    catch (bad_cast)
    {
        cout << "cast Query_base to AndQuery failed" << endl;
    }

    return 0;
}

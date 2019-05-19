#include <iostream>
#include "Query.h"
#include "AndQuery.h"
#include "NotQuery.h"

using namespace std;

int main()
{
    Query_base *pb = new AndQuery();

    if (AndQuery *pa = dynamic_cast<AndQuery*>(pb))
        cout << "cast Query_base to AndQuery succeed" << endl;
    else
        cout << "cast Query_base to AndQuery failed" << endl;

    delete pb;

    pb = new NotQuery();

    if (AndQuery *pa = dynamic_cast<AndQuery*>(pb))
        cout << "cast Query_base to AndQuery succeed" << endl;
    else
        cout << "cast Query_base to AndQuery failed" << endl;

    delete pb;

    return 0;
}

#include "Query.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: ./a.out filename" << endl;
        return 1;
    }

    TextQuery tq(argv[1]);

    Query q = Query("fiery") & Query("bird") | Query("wind");
    cout << q.eval(tq);
    q = Query("Daddy");
    cout << q.eval(tq);
    q = ~Query("Alice");
    cout << q.eval(tq);
    q = Query("hair") | Query("Alice");
    cout << q.eval(tq);

    return 0;
}

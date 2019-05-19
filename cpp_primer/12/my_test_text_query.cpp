#include <iostream>
#include <string>
#include "MyTextQuery.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Usage: ./a.out filename word" << endl;
        return 1;
    }

    TextQuery tq(argv[1]);
    tq.text_query(argv[2]);

    return 0;
}

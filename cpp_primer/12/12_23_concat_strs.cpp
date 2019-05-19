#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    char cat[15] = "hello ";
    char dog[] = "world";
    
    strcat(cat, dog);

    char *msg = new char[15];

    strcpy(msg, cat);

    for (char *pc = msg; pc != msg + 12; ++pc)
        cout << *pc;
    cout << endl;

    string foo("hello ");
    string bar("world");
    cout << foo + bar << endl;

    return 0;
}

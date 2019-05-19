#include <iostream>
#include "StrVec.h"

using namespace std;

void *operator new(size_t sz)
{
    cout << "new " << sz << endl; 
    if (void *mem = malloc(sz))
        return mem;
    else
        throw bad_alloc();
}

void operator delete(void *mem) noexcept
{
    cout << "delete " << mem << endl;
    free(mem);
}

int main()
{
    StrVec vs;
    string word;
    cout << "Enter some words:" << endl;

    while (cin >> word)
        vs.push_back(word);

    for (auto &s : vs)
        cout << s << endl;

    return 0;
}

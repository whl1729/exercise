#include <iostream>
#include <stdexcept>

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
    int *foo = new int(5);
    cout << *foo << endl;
    *foo = 1729;
    cout << *foo << endl;
    delete foo;

    return 0;
}

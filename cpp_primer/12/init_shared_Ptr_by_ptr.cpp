#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> foo(new int);
    *foo = 100;
    cout << *foo << " " << foo.use_count() << endl;
    shared_ptr<int> bar(foo);
    cout << *foo << " " << foo.use_count() << endl;
    cout << *bar << " " << bar.use_count() << endl;
    shared_ptr<int> egg(foo.get());
    cout << *foo << " " << foo.use_count() << endl;
    cout << *bar << " " << bar.use_count() << endl;
    cout << *egg << " " << egg.use_count() << endl;

    return 0;
}

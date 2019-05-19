#include <iostream>
#include "String.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    String foo;
    cout << "foo: " << foo << endl;

    String bar("hello world");
    cout << "bar: " << bar << endl;

    String cat(10, 'c');
    cout << "cat: " << cat << endl;

    String *dog = new String(cat);
    cout << "*dog: " << *dog << endl;
    delete dog;

    foo += bar;
    cout << "foo += bar, foo: " << foo << endl;

    foo += " and hello tomorrow";
    cout << "foo +=\" and hello tomorrow\", foo: " << foo << endl;
    cout << "foo.size = " << foo.size() << ", foo.capacity = " << foo.capacity() << endl;

    foo.reserve(5);
    cout << "foo.reserve(5), foo.size = " << foo.size() << ", foo.capacity = " << foo.capacity() << endl;
    foo.reserve(50);
    cout << "foo.reserve(50), foo.size = " << foo.size() << ", foo.capacity = " << foo.capacity() << endl;
    foo.resize(5);
    cout << "foo.resize(5), foo.size = " << foo.size() << ", foo.capacity = " << foo.capacity() << endl;
    foo.resize(50);
    cout << "foo.resize(50), foo.size = " << foo.size() << ", foo.capacity = " << foo.capacity() << endl;

    String egg;
    cout << "Enter a String: ";
    cin >> egg;
    cout << "You enter: " << egg << endl;

    return 0;
}

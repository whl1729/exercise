#include <iostream>
#include <list>

using namespace std;

class X {};
class Y : public virtual X {};
class Z : public virtual X {};
class A : public Y, public Z {};

class P : public X {};
class Q : public X {};
class T : public P, public Q {};

class C : public X { int i; };
class B { int *pi; };

class Point3d
{
    float x;
    static list<Point3d*> *freeList;
    float y;
    static const int chunkSize = 250;
    float z;
};

int main()
{
    cout << "sizeof X yielded " << sizeof(X) << endl;
    cout << "sizeof Y yielded " << sizeof(Y) << endl;
    cout << "sizeof Z yielded " << sizeof(Z) << endl;
    cout << "sizeof A yielded " << sizeof(A) << endl;
    cout << "sizeof P yielded " << sizeof(P) << endl;
    cout << "sizeof Q yielded " << sizeof(Q) << endl;
    cout << "sizeof T yielded " << sizeof(T) << endl;
    cout << "sizeof C yielded " << sizeof(C) << endl;
    cout << "sizeof B yielded " << sizeof(B) << endl;
    cout << "sizeof Point3d yielded " << sizeof(Point3d) << endl;

    X a, b;
    if (&a == &b)
        cerr << "yipes!" << endl;

    return 0;
}

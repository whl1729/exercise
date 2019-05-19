#include <iostream>
#include <list>

using namespace std;

class Point3d
{
public:
    float x;
    static list<Point3d*> freeList;
    float y;
    static const int chunkSize = 250;
    float z;
    Point3d(): x(0), y(0), z(0) {}
    void print() { cout << "(" << x << ", " << y << ", " << z << ")" << endl; }
};

int main()
{
    Point3d origin;
    float *pf = &origin + (&Point3d::y - 1);
    cout << "&origin.y: " << &origin.y << endl;
    cout << "&origin + (&Point3d::y - 1): " << pf << endl;

    *pf = 1729.0;
    origin.print();

    return 0;
}

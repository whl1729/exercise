#include <iostream>
#include <list>
#include <cassert>

using namespace std;

class Point3d
{
public:
    float x;
    static list<Point3d*> *freeList;
    float y;
    static const int chunkSize = 250;
    float z;
};

template <class class_type, class data_type1, class data_type2>
char *access_order(data_type1 class_type::*mem1, data_type2 class_type::*mem2)
{
    assert(mem1 != mem2);
    return ((mem1 < mem2) ? "member 1 occurs first" : "member 2 occurs first");
}

int main()
{
    cout << access_order(&Point3d::y, &Point3d::z) << endl;
    return 0;
}

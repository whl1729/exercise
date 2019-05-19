#include <iostream>
#include <stdio.h>

using namespace std;

class Point3d
{
public:
    float x;
    int i;
    float y;
    int j;
    float z;
};

int main()
{
    cout << &Point3d::x << " " << &Point3d::y << " " << &Point3d::z << endl;
    return 0;
}

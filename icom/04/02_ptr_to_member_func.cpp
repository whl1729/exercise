#include <iostream>

using namespace std;

class Point
{
public:
    virtual ~Point() {}
    float x() { return _x; }
    float y() { return _y; }
    virtual float z() { return 0; }
private:
    float _x;
    float _y;
};

int main()
{
//    cout << &Point::~Point << endl;
    cout << &Point::x << endl;
    cout << &Point::y << endl;
    cout << &Point::z << endl;

    return 0;
}

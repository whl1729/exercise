#include <iostream>

using namespace std;

typedef int length;

class Point3d
{
public:
    typedef float length;
    void mumble(length val) { _val = val; }
    length mumble() { return _val; }
private:
    length _val;
};

int main()
{
    Point3d point;
    cout << point.mumble() << endl;
    return 0;
}

#include <iostream>
using namespace std;

class alloc {};

template <class T, class Alloc = alloc>
class vector
{
public:
    vector() { cout << "vector<T, Alloc>" << endl; }
    void swap(vector<T, Alloc>&) { cout << "swap()" << endl; }
};

int main()
{
    vector<int> x, y;
    swap(x, y);
    return 0;
}

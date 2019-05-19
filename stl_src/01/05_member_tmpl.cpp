#include <iostream>
using namespace std;

// 测试 class template之内可否再有template members

class alloc {};

template <class T, class Alloc = alloc>
class vector
{
public:
    typedef T value_type;
    typedef value_type* iterator;

    template <class I>
    void insert(iterator pos, I first, I last)
    {
        cout << "insert()" << endl;
    }
};

int main()
{
    int ia[5] = {0,1,2,3,4};

    vector<int> x;
    vector<int>::iterator iter;
    x.insert(iter, ia, ia+5);
    
    return 0;
}

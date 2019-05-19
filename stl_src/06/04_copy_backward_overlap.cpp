#include <iostream>
#include <algorithm>
#include <deque>
#include <numeric>

using namespace std;

template <class T>
struct display
{
    void operator()(const T &x) { cout << x << ' '; }
};

int main()
{
    // 输出区间的终点与输入区间重叠
    int ia[] = {0,1,2,3,4,5,6,7,8};
    
    copy_backward(ia+2, ia+7, ia+9);
    for_each(ia, ia+9, display<int>());
    cout << endl;

    // 输出区间的起点与输入区间重叠
    iota(ia, ia+9, 0);
    
    copy_backward(ia+2, ia+7, ia+5);
    for_each(ia, ia+9, display<int>());
    cout << endl;

    // 输出区间的终点与输入区间重叠
    iota(ia, ia+9, 0);
    deque<int> id(ia, ia+9);

    auto first = id.begin();
    auto last = id.end();
    ++++first;
    cout << *first << endl;
    ----last;
    cout << *last << endl;

    auto result = id.end();
    cout << *result << endl;

    copy_backward(first, last, result);
    for_each(id.begin(), id.end(), display<int>());
    cout << endl;

    // 输出区间的起点与输入区间重叠
    iota(ia, ia+9, 0);
    id = deque<int>(ia, ia+9);

    first = id.begin();
    last = id.end();
    ++++first;
    cout << *first << endl;
    ----last;
    cout << *last << endl;

    result = id.begin();
    advance(result, 5);
    cout << *result << endl;

    copy_backward(first, last, result);
    for_each(id.begin(), id.end(), display<int>());
    cout << endl;

    return 0;
}

#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    deque<int> id{32,26,99,1,0,1,2,3,4,0,1,2,5,3};
    
    cout << *(id.begin()) << endl;
    cout << *(id.rbegin()) << endl;
    cout << *(id.end()) << endl;
    cout << *(id.rend()) << endl;

    auto ite = find(id.begin(), id.end(), 99);
    reverse_iterator<deque<int>::iterator> rite(ite);
    cout << *ite << endl;
    cout << *rite << endl;

    return 0;
}

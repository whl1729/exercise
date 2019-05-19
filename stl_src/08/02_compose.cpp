#include <algorithm>
#include <ext/functional>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;
using __gnu_cxx::compose1;

int main()
{
    ostream_iterator<int> outite(cout, " ");
    int ia[6] = {2,21,12,7,19,23};
    vector<int> iv(ia, ia+6);

    for_each(iv.begin(), iv.end(), compose1(
                bind2nd(multiplies<int>(), 3), 
                bind2nd(plus<int>(), 2)));
    copy(iv.begin(), iv.end(), outite);
    cout << endl;

    transform(iv.begin(), iv.end(), outite, compose1(
                bind2nd(multiplies<int>(), 3),
                bind2nd(plus<int>(), 2)));
    cout << endl;

    return 0;
}

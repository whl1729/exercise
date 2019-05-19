#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <class T>
struct display
{
    void operator()(const T &x) { cout << x << ' '; }
};

int main()
{
    int ia1[6] = {1,3,5,7,9,11};
    int ia2[7] = {1,1,2,3,5,8,13};

    multiset<int> s1(ia1, ia1+6);
    multiset<int> s2(ia2, ia2+7);

    for_each(s1.begin(), s1.end(), display<int>());
    cout << endl;
    for_each(s2.begin(), s2.end(), display<int>());
    cout << endl;

    auto first1 = s1.begin();
    auto last1 = s1.end();
    auto first2 = s2.begin();
    auto last2 = s2.end();

    cout << "union of s1 and s2: ";
    set_union(first1, last1, first2, last2, 
              ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "intersection of s1 and s2: ";
    set_intersection(first1, last1, first2, last2, 
              ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "difference of s1 and s2 (s1-s2): ";
    set_difference(first1, last1, first2, last2, 
              ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "symmetric_difference of s1 and s2: ";
    set_symmetric_difference(first1, last1, first2, last2, 
              ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "difference of s2 and s1 (s2-s1): ";
    set_difference(first2, last2, first1, last1, 
              ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

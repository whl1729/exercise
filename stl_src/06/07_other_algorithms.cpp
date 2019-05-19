#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>

using namespace std;

struct even
{
    bool operator()(int x) const { return x%2 ? false : true; }
};

int main()
{
    int ia[] = {12,17,20,22,23,30,33,40};
    vector<int> iv(ia, ia + sizeof(ia)/sizeof(int));

    cout << *lower_bound(iv.begin(), iv.end(), 21) << endl;
    cout << *upper_bound(iv.begin(), iv.end(), 21) << endl;
    cout << *lower_bound(iv.begin(), iv.end(), 22) << endl;
    cout << *upper_bound(iv.begin(), iv.end(), 22) << endl;

    cout << binary_search(iv.begin(), iv.end(), 33) << endl;
    cout << binary_search(iv.begin(), iv.end(), 34) << endl;

//    for (int i = 0; i < 2*3*4*5*6*7*8; ++i)
    {
        next_permutation(iv.begin(), iv.end());
        copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    prev_permutation(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    random_shuffle(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    partial_sort(iv.begin(), iv.begin()+4, iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(iv.begin(), iv.end(), greater<int>());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    iv.push_back(22);
    iv.push_back(30);
    iv.push_back(17);

    stable_sort(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    pair<vector<int>::iterator, vector<int>::iterator> pairIte;
    pairIte = equal_range(iv.begin(), iv.end(), 22);
    cout << *(pairIte.first) << endl;
    cout << *(pairIte.second) << endl;

    pairIte = equal_range(iv.begin(), iv.end(), 25);
    cout << *(pairIte.first) << endl;
    cout << *(pairIte.second) << endl;

    random_shuffle(iv.begin(), iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    nth_element(iv.begin(), iv.begin()+5, iv.end());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    nth_element(iv.begin(), iv.begin()+5, iv.end(), greater<int>());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    stable_partition(iv.begin(), iv.end(), even());
    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

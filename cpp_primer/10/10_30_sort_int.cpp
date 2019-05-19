#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vi;

    copy(in_iter, eof, back_inserter(vi));
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), out_iter);

    cout << endl;
    return 0;
}

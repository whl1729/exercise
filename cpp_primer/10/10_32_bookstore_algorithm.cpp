#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "Sales_item.h"

using namespace std;

int main()
{
    vector<Sales_item> vs;
    istream_iterator<Sales_item> in_iter(cin), eof;

    copy(in_iter, eof, back_inserter(vs));

    sort(vs.begin(), vs.end(),
         [] (const Sales_item &a, const Sales_item &b) 
         { return a.isbn() < b.isbn(); });

    auto vbeg = vs.begin();
    while (vbeg != vs.end())
    {
        auto vend = find_if(vbeg, vs.end(), 
                       [&vbeg] (const Sales_item &it)
                       { return vbeg->isbn() != it.isbn(); });

        auto sum = accumulate(vbeg, vend, Sales_item(vbeg->isbn()));
        cout << sum << endl;
        vbeg = vend;
    }

    return 0;
}

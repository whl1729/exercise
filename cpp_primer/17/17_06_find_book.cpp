#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Sales_data.h"

using namespace std;

struct matches
{
    matches(vector<Sales_data>::size_type i,
            vector<Sales_data>::const_iterator b,
            vector<Sales_data>::const_iterator e): id(i), beg(b), end(e) { }
    vector<Sales_data>::size_type id;
    vector<Sales_data>::const_iterator beg;
    vector<Sales_data>::const_iterator end;
};

vector<matches> find_book(const vector<vector<Sales_data>> &files,
                          const string &book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = equal_range(it->cbegin(), it->cend(),
                                 book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(matches(it - files.cbegin(), 
                                  found.first, found.second));
    }
    return ret;
}

void report_result(istream &in, ostream &os, 
                   const vector<vector<Sales_data>> &files)
{
    string s;
    os << "Enter book's name to query: " << endl;
    while (getline(in, s))
    {
        auto trans = find_book(files, s);
        if (trans.empty())
        {
            cout << s << " not found in any stores" << endl;
            continue;
        }
        for (const auto &store : trans)
            os << "store " << store.id << " sales: "
               << accumulate(store.beg, store.end, Sales_data(s))
               << endl;
    }
}

int main()
{
    vector<Sales_data> xinhua;
    xinhua.push_back(Sales_data("The Old Man and The Sea", 10, 32));
    xinhua.push_back(Sales_data("Walden", 5, 50));
    xinhua.push_back(Sales_data("Walden", 3, 60));
    xinhua.push_back(Sales_data("Walden", 2, 75));

    vector<Sales_data> sanlian;
    sanlian.push_back(Sales_data("Bibile", 7, 58));
    sanlian.push_back(Sales_data("LunYu", 1, 30));
    sanlian.push_back(Sales_data("The Old Man and The Sea", 3, 64));

    vector<Sales_data> hongtaiyang;
    hongtaiyang.push_back(Sales_data("LunYu", 5, 20));
    hongtaiyang.push_back(Sales_data("Walden", 7, 58));
    hongtaiyang.push_back(Sales_data("Walden", 3, 64));

    vector<Sales_data> panzhou;
    panzhou.push_back(Sales_data("Bible", 6, 28));
    panzhou.push_back(Sales_data("LunYu", 2, 25));
    panzhou.push_back(Sales_data("Walden", 3, 64));

    vector<vector<Sales_data>> trans{xinhua, sanlian, hongtaiyang, panzhou};

    report_result(cin, cout, trans);

    return 0;
}

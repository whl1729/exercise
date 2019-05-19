#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> sset;

    sset.insert("pengcheng");
    sset.insert(string("jazz"));
    sset.insert("achao");
    sset.insert(string("along"));
    sset.insert("dj");

    for (auto &s : sset)
        cout << s << " ";
    cout << endl;

    unordered_set<double> dset;

    dset.insert(3.14);
    dset.insert(1.732);
    dset.insert(1.414);
    dset.insert(2.7);

    for (auto d : dset)
        cout << d << " ";
    cout << endl;

    return 0;
}

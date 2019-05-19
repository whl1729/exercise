#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{1729, 384, 361, 999};

    cout << ivec.at(0) << endl;
    cout << ivec[0] << endl;
    cout << ivec.front() << endl;
    cout << *ivec.begin() << endl;

    vector<int> jvec;

    cout << jvec.at(0) << endl;
    cout << jvec[0] << endl;
    cout << jvec.front() << endl;
    cout << *jvec.begin() << endl;

    return 0;
}

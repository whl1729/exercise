#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i;
    vector<int> iv(5,9);
    cout << "size=" << iv.size() << endl;
    cout << "capacity=" << iv.capacity() << endl;

    for (i = 1; i < 5; ++i)
    {
        iv.push_back(i);
        cout << "size=" << iv.size() << endl;
        cout << "capacity=" << iv.capacity() << endl;
    }

    for (i = 0; i < iv.size(); ++i)
        cout << iv[i] << ' ';
    cout << endl;

    iv.push_back(5);


    cout << "size=" << iv.size() << endl;
    cout << "capacity=" << iv.capacity() << endl;
    for (i = 0; i < iv.size(); ++i)
        cout << iv[i] << ' ';
    cout << endl;

    iv.pop_back();
    iv.pop_back();
    cout << "size=" << iv.size() << endl;
    cout << "capacity=" << iv.capacity() << endl;

    iv.pop_back();
    vector<int>::iterator ivite = find(iv.begin(), iv.end(), 1);
    if (ivite != iv.end())
        iv.erase(ivite);
    cout << "size=" << iv.size() << endl;
    cout << "capacity=" << iv.size() << endl;
    for (i = 0; i < iv.size(); ++i)
        cout << iv[i] << ' ';
    cout << endl;

    ivite = find(iv.begin(), iv.end(), 2);
    if (ivite != iv.end())
        iv.insert(ivite, 10, 7);

    cout << "size=" << iv.size() << endl;
    cout << "capacity=" << iv.capacity() << endl;
    for (i = 0; i < iv.size(); ++i)
        cout << iv[i] << ' ';
    cout << endl;

    iv.clear();
    cout << "size=" << iv.size() << endl;
    cout << "capacity=" << iv.capacity() << endl;

    return 0;
}

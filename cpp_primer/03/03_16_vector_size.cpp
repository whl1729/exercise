#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;

    cout << "size: " << v1.size() << endl;

    for (auto v : v1)
        cout << v << ' ';
    cout << endl;

    vector<int> v2(10);

    cout << "size: " << v2.size() << endl;

    for (auto v : v2)
        cout << v << ' ';
    cout << endl;

    vector<int> v3(10, 42);

    cout << "size: " << v3.size() << endl;

    for (auto v : v3)
        cout << v << ' ';
    cout << endl;

    vector<int> v4{10};

    cout << "size: " << v4.size() << endl;

    for (auto v : v4)
        cout << v << ' ';
    cout << endl;

    vector<int> v5{10, 42};

    cout << "size: " << v5.size() << endl;

    for (auto v : v5)
        cout << v << ' ';
    cout << endl;

    vector<string> v6{10};

    cout << "size: " << v6.size() << endl;

    for (auto v : v6)
        cout << v << ' ';
    cout << endl;

    vector<string> v7{10, "hi"};

    cout << "size: " << v7.size() << endl;

    for (auto v : v7)
        cout << v << ' ';
    cout << endl;

    return 0;
}

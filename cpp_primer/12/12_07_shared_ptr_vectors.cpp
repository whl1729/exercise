#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> alloc_vec()
{
    shared_ptr<vector<int>> pvi = make_shared<vector<int>>();
    return pvi;
}

void set_vec(shared_ptr<vector<int>> pvi)
{
    int data;
    cout << "Enter numbers: " << endl;
    while (cin >> data)
        pvi->push_back(data);
}

void print_vec(shared_ptr<vector<int>> pvi)
{
    for (auto i : *pvi)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    shared_ptr<vector<int>> pvi = alloc_vec();

    set_vec(pvi);

    print_vec(pvi);

    return 0;
}

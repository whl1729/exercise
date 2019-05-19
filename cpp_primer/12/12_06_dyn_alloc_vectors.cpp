#include <iostream>
#include <vector>

using namespace std;

vector<int> *alloc_vec()
{
    vector<int> *pvi = new vector<int>;
    return pvi;
}

void set_vec(vector<int> *pvi)
{
    int data;
    cout << "Enter numbers: " << endl;
    while (cin >> data)
        pvi->push_back(data);
}

void print_vec(vector<int> *pvi)
{
    for (auto i : *pvi)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    vector<int> *pvi = alloc_vec();

    set_vec(pvi);

    print_vec(pvi);

    free(pvi);

    return 0;
}

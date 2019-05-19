#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>::iterator begin, vector<int>::iterator end)
{
#ifndef NDEBUG
    cerr << __func__ << ": array size is " << end - begin << endl;
#endif
    if (begin != end)
    {
        cout << *begin << endl;
        print_vector(++begin, end);
    }
}

int main()
{
    vector<int> vi;
    int num;

    cout << "Enter numbers: " << endl;

    while (cin >> num)
        vi.push_back(num);

    print_vector(vi.begin(), vi.end());

    return 0;
}

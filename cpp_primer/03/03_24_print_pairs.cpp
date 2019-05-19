#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    decltype(vi.begin()) it, bit, eit;
    int num;

    while (cin >> num)
        vi.push_back(num);

    for (it = vi.begin(); it < vi.end() - 1; it+=2)
    {
        cout << *it + *(it+1) << ' ';
    }

    if (it == vi.end() - 1)
        cout << *it; 
    
    cout << endl;

    for (bit = vi.begin(), eit = vi.end() - 1; bit < eit; bit++, eit--)
    {
        cout << *bit + *eit << ' ';
    }

    if (bit == eit)
        cout << *bit;

    cout << endl;

}

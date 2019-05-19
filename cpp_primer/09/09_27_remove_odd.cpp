#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> flst;
    int num;

    cout << "Enter numbers: " << endl;

    while (cin >> num)
        flst.push_front(num);

    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr & 0x1)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for (auto i: flst)
        cout << i << ' ';
    cout << endl;

    return 0;
}

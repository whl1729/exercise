#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    const int size = 100;
    allocator<string> alloc;
    string word;

    auto beg = alloc.allocate(size);
    auto cur = beg;

    cout << "Enter some words:" << endl;
    for (; cin >> word && cur != beg + size; ++cur)
    {
        alloc.construct(cur, word);
    }

    for (; cur >= beg; --cur)
    {
        cout << *cur << ' ';
        alloc.destroy(cur);
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi{0,2,4,6,8,1,3,5,7,9};

    auto iter = vi.begin();

    while (iter != vi.end())
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        ++iter;

    return 0;
}

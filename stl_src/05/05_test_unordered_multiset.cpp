#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_multiset<int> iset(50);

    cout << iset.size() << endl;
    cout << iset.bucket_count() << endl;
    cout << iset.max_bucket_count() << endl;

    int arr[] = {59, 63, 108, 2, 53, 55};
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
        iset.insert(arr[i]);    
    cout << iset.size() << endl;

    for (auto iter = iset.begin(); iter != iset.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    for (int i = 0; i < iset.bucket_count(); ++i)
    {
        int n = iset.bucket_size(i);
        if (n != 0)
            cout << "bucket[" << i << "] has " << n << " elems." << endl;
    }

    for (int i = 0; i <= 47; ++i)
        iset.insert(i);

    cout << iset.size() << endl;
    cout << iset.bucket_count() << endl;

    for (int i = 0; i < iset.bucket_count(); ++i)
    {
        int n = iset.bucket_size(i);
        if (n != 0)
            cout << "bucket[" << i << "] has " << n << " elems." << endl;
    }

    for (auto iter = iset.begin(); iter != iset.end(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    cout << *(iset.find(2)) << endl;
    cout << iset.count(2) << endl;

    return 0;
}

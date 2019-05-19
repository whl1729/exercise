#include <iostream>
#include "StrBlob.h"

using namespace std;

int main()
{
    StrBlob blob;
    string words[] = {"just", "the", "way", "you", "are"};

    for (int pos = 0; pos < 5; ++pos)
        blob.push_back(words[pos]);

    for (auto beg = blob.begin(); beg != blob.end(); beg.incr())
        cout << beg.deref() << " ";
    cout << endl;

    StrBlobPtr ptr(blob);
    cout << "*ptr=" << *ptr << " ptr->size()=" << ptr->size() << endl;
    cout << "ptr(blob), *ptr: " << ptr.deref() << endl;
    ptr += 1;
    cout << "ptr += 1, *ptr: " << ptr.deref() << endl;
    ptr = ptr + 2;
    cout << "ptr = ptr + 2, *ptr: " << ptr.deref() << endl;
    ptr++;
    cout << "ptr++, *ptr: " << ptr.deref() << endl;
    cout << "--ptr, *ptr: " << (--ptr).deref() << endl;
    ptr -= 2;
    cout << "ptr -= 2, *ptr: " << ptr.deref() << endl;

    return 0;
}

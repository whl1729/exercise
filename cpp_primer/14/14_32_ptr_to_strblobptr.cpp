#include <iostream>
#include "StrBlob.h"

class BlobPptr
{
public:
    BlobPptr(StrBlobPtr *p): ptr(p) {}
    StrBlobPtr& operator*() const { return *ptr; }
    StrBlobPtr* operator->() const { return ptr; }
private:
    StrBlobPtr *ptr;
};

int main()
{
    StrBlob blob{"wanna", "be", "free"};
    StrBlobPtr bp(blob);
    BlobPptr ppt(&bp);

    cout << "*bp: " << *bp << ", bp->size: " << bp->size() << endl;
    cout << "(*ppt).deref: " << (*ppt).deref() << ", ppt->size: " << ppt->deref().size() << endl;

    return 0;
}

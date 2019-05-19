#ifndef __DEBUGDELETE_H__
#define __DEBUGDELETE_H__

#include <iostream>

using std::ostream;

class DebugDelete
{
public:
    DebugDelete(ostream &s = std::cerr): os(s) { }
    template <typename T> void operator()(T *p) const
    {
        os << "deleting unique_ptr " << std::endl;
        delete p;
    }
private:
    ostream &os;
};

#endif

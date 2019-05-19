#include <iostream>
#include <stdexcept>

using namespace std;

class ExceptionType
{

};

int main()
{
    try
    {
        throw new ExceptionType();
    }
    catch(ExceptionType *pet)
    {
        cout << "catch(ExceptionType *pet)" << endl;
    }

    try
    {
        throw exception();
    }
    catch(invalid_argument expt)
    {
        cout << expt.what() << endl;
    }
    catch(...)
    {
        cout << "catch(...)" << endl;
    }

    try
    {
        throw 1729;
    }
    catch(int expt)
    {
        cout << "catch(int expt), expt=" << expt << endl;
    }
    catch(exception expt)
    {
        cout << expt.what() << endl;
    }

    return 0;
}

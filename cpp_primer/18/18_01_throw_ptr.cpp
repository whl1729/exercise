#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        try
        {
            range_error r("range error");
            exception *p = &r;
            throw p;
        }
        catch (overflow_error expt)
        {
            cout << expt.what() << endl;
        }
    }
    catch (exception *expt)
    {
        cout << expt->what() << endl;
    }

    return 0;
}

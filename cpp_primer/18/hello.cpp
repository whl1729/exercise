#include <iostream>
#include <stdexcept>

using namespace std;

void hey() noexcept
{
    try
    {
        throw exception();
    }
    catch (exception expt)
    {
        cout << expt.what() << endl;
    }
}

void play()
{
    throw exception();
}

void chok()
{
    play();
}

int main()
{
    int foo = 5;
    int bar = 0;

    hey();

    cout << boolalpha 
         << "hey: " << noexcept(hey) 
         << " play: " << noexcept(play)
         << " chok: "  << noexcept(chok) 
         << noboolalpha << endl;

    try
    {
        cout << "entering try 1" << endl;
        try
        {
            cout << "entering try 2" << endl;
            if (!bar)
                throw invalid_argument("divide 0");
            foo /= bar;
            cout << "leaving try 2" << endl;
        }
        catch (overflow_error expt)
        {
            cout << "entering catch 2" << endl;
            cout << expt.what() << endl;
            cout << "leaving catch 2" << endl;
        }
        cout << "leaving try 1" << endl;
    }
    catch (invalid_argument expt)
    {
        cout << "entering catch 1" << endl;
        cout << expt.what() << endl;
        cout << "leaving catch 1" << endl;
    }

    cout << "leaving main" << endl;

    return 0;
}

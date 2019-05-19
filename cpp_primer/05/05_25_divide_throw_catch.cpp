#include <iostream>

using namespace std;

int main()
{
    int foo, bar;

    cout << "Enter two integers: " << endl;

    while (cin >> foo >> bar)
    {
        try
        {
            if (bar == 0)
                throw runtime_error("Error: Divide 0.");

            cout << foo << " / " << bar << " = " << foo / bar << endl;
            break;
        }
        catch (runtime_error err)
        {
            cout << err.what() 
                 << "\nTry Again? Enter y or n" << endl;

            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }

    return 0;
}

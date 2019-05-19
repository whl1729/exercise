#include <iostream>

using namespace std;

int main()
{
    string word;
    const int threshold = 5;

    cout << "Enter a word: " << endl;
    cin >> word;

    if (word.size() < threshold)
        cerr << "Error " << __FILE__
             << " : in function " << __func__
             << " at line " << __LINE__ << endl
             << "       Compiled on " << __DATE__
             << " at " << __TIME__ << endl
             << "       Word read was \"" << word
             << "\": Length too short" << endl;

    return 0;
}

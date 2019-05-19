#include <iostream>
#include "Girl.h"

using namespace std;

int main()
{
    Girl lucy;
    Girl star;

    cout << (star ? "someone" : "nobody") << endl;

    cout << "Enter some woman stars: " << endl;
    cin >> star;
    if (star == lucy)
        cout << "The star is Lucy." << endl;
    else
        cout << "The start isn't Lucy" << endl;

    while (cin >> star)
        cout << star << endl;

    return 0;
}

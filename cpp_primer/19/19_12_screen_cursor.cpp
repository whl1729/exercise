#include <iostream>
#include "Screen.h"

using namespace std;

int main()
{
    const size_t Screen<4,5>::*pc = Screen<4,5>::pcursor();
    Screen<4,5> sc('-');
    cout << "cursor: " << sc.*pc << endl;
    sc.move(10);
    cout << "cursor: " << sc.*pc << endl;
    return 0;
}

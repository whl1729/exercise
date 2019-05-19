#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    tuple<int, int, int> threeInt(10, 20, 30);
    cout << get<0>(threeInt) << " "
         << get<1>(threeInt) << " "
         << get<2>(threeInt) << endl;

    return 0;
}

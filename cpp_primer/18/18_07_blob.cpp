#include <iostream>
#include <vector>
#include <string>
#include "Blob.h"

using namespace std;

int main()
{
    vector<string> svec{"ocean's", "apart", "day", "after", "day"};
    string foo, bar;
    Blob<string> sbb(svec.begin(), svec.end());
    cout << sbb << endl;

    return 0;
}

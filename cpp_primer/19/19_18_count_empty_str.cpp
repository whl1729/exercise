#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    vector<string> vs{"", "hi", "", "nice", "come on", "", "bye"};
    cout << "# empty str : " 
         << count_if(vs.begin(), vs.end(), mem_fn(&string::empty))
         << endl;

    return 0;
}

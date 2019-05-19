#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    vector<string> svec{"When", "I", "see", "your", "face"};
    pair<string, int> book{"Walden", 50};
    tuple<string, vector<string>, pair<string, int>> svp("Mary", svec, book);

    cout << get<0>(svp) << endl;

    for (auto &s : get<1>(svp))
        cout << s << " ";
    cout << endl;

    cout << get<2>(svp).first << " " << get<2>(svp).second << endl;

    return 0;
}

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    string word;
    istream_iterator<int> in(cin);
    cout << "please input a word: " << endl;
    cin >> word;
    cout << "(" << word << ")" << endl;
    cout << *in << endl;

    return 0;
}

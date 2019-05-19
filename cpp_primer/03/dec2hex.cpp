#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    const string hex_digits = "0123456789ABCDEF";

    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. hit ENTER when finished: "
         << endl;

    string result;
    string::size_type n;

    while (cin >> n)
        if (n < hex_digits.size())
            result += hex_digits[n];

    cout << "Your hex number is 0x" << result << endl;
}

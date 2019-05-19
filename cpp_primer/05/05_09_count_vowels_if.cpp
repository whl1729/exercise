#include <iostream>

using namespace std;

int main()
{
    int a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    char ch;

    while (cin >> ch)
    {
        ch = tolower(ch);

        if (ch =='a')
            a_cnt++;
        else if (ch == 'e')
            e_cnt++;
        else if (ch == 'i')
            i_cnt++;
        else if (ch == 'o')
            o_cnt++;
        else if (ch == 'u')
            u_cnt++;
    }

    cout << "Number of vowel a: " << a_cnt << '\n'
         << "Number of vowel e: " << e_cnt << '\n'
         << "Number of vowel i: " << i_cnt << '\n'
         << "Number of vowel o: " << o_cnt << '\n'
         << "Number of vowel u: " << u_cnt << endl;

    return 0;
}

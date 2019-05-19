#include <iostream>

using namespace std;

int main()
{
    unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    char ch;

    while (cin >> ch) 
    {
        switch (ch)
        {
            case 'a':
                ++a_cnt;
                break;
            case 'e':
                ++e_cnt;
                break;
            case 'i':
                ++i_cnt;
                break;
            case 'o':
                ++o_cnt;
                break;
            case 'u':
                ++u_cnt;
                break;
        }
    }

    cout << "Number of vowel a: \t" << a_cnt << '\n'
         << "Number of vowel e: \t" << e_cnt << '\n'
         << "Number of vowel i: \t" << i_cnt << '\n'
         << "Number of vowel o: \t" << o_cnt << '\n'
         << "Number of vowel u: \t" << u_cnt << endl;

    return 0;
}

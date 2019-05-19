#include <iostream>

using namespace std;

int main()
{
    unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    unsigned b_cnt = 0, t_cnt = 0, n_cnt = 0;
    char ch;

    while (cin.get(ch)) 
    {
        ch = tolower(ch);

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
            case ' ':
                ++b_cnt;
                break;
            case '\t':
                ++t_cnt;
                break;
            case '\n':
                ++n_cnt;
                break;
            default:
                break;
        }
    }

    cout << "Number of vowel a: \t" << a_cnt << '\n'
         << "Number of vowel e: \t" << e_cnt << '\n'
         << "Number of vowel i: \t" << i_cnt << '\n'
         << "Number of vowel o: \t" << o_cnt << '\n'
         << "Number of vowel u: \t" << u_cnt << '\n'
         << "Number of blank space: \t" << b_cnt << '\n'
         << "Number of tab: \t" << t_cnt << '\n'
         << "Number of newline: \t" << n_cnt << endl;

    return 0;
}

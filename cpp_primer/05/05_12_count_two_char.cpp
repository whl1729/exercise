#include <iostream>

using namespace std;

int main()
{
    unsigned a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    unsigned ff_cnt = 0, fl_cnt = 0, fi_cnt = 0;
    char last = 0;
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
                if (last == 'f')
                    ++fi_cnt;
                break;
            case 'o':
                ++o_cnt;
                break;
            case 'u':
                ++u_cnt;
                break;
            case 'f':
                if (last == 'f')
                    ++ff_cnt;
                break;
            case 'l':
                if (last == 'f')
                    ++fl_cnt;
                break;
            default:
                break;
        }

        if (last == 'f' && ch == 'f')
            last = 0;
        else
            last = ch;
    }

    cout << "Number of vowel a: \t" << a_cnt << '\n'
         << "Number of vowel e: \t" << e_cnt << '\n'
         << "Number of vowel i: \t" << i_cnt << '\n'
         << "Number of vowel o: \t" << o_cnt << '\n'
         << "Number of vowel u: \t" << u_cnt << '\n'
         << "Number of vowel ff: \t" << ff_cnt << '\n'
         << "Number of vowel fi: \t" << fi_cnt << '\n'
         << "Number of vowel fl: \t" << fl_cnt << endl;

    return 0;
}

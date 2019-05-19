#include <iostream>

using namespace std;

int main()
{
    string dupl, prev, word;
    int max_cnt = 0, cur_cnt = 0;

    while (cin >> word)
    {
        if (word == prev)
            ++cur_cnt;
        else
        {
            if (cur_cnt > max_cnt)
            {
                dupl = prev;
                max_cnt = cur_cnt;
            }

            cur_cnt = 1;
            prev = word;
        }
    }

    if (cur_cnt > max_cnt)
    {
        dupl = word;
        max_cnt = cur_cnt;
    }

    if (max_cnt <= 1)
        cout << "No word was repeated." << endl;
    else
        cout << dupl << " occurred " << max_cnt << " times." << endl;
}

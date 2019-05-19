#include <iostream>

using namespace std;

int main()
{
    constexpr size_t row_cnt = 3, col_cnt = 4;
    int ia[row_cnt][col_cnt];

    for (size_t i = 0; i < row_cnt; i++)
        for (size_t j = 0; j < col_cnt; j++)
            ia[i][j] = i * col_cnt + j;

    for (int (&a)[col_cnt]: ia)
    {
        for (int b : a)
            cout << b << ' ';
        cout << endl;
    }

    cout << endl;

    for (size_t i = 0; i < row_cnt; i++)
    {
        for (size_t j = 0; j < col_cnt; j++)
            cout << ia[i][j] << ' ';
        cout << endl;
    }

    cout << endl;

    int *start = &ia[0][0];
    int *end = &ia[row_cnt-1][col_cnt-1];

    for (; start <= end; start++)
        cout << *start << ' ';
    cout << endl;

    return 0;
}

#include <iostream>

using namespace std;

void print(const int *beg, const int *end);
void print(const int ia[], size_t size);
void print(int (&arr)[2]);
void print(int (*matrix)[10], int row_size);
//void print(int matrix[][10], int row_size);

int main()
{
    int i = 0, j[2] = {0, 1};
    int *ptr = &i;

    print(ptr, ptr+1);
    print(ptr, 1);
    //print(ptr);

    print(begin(j), end(j));
    print(j, 2);
    print(j);

    return 0;
}


void print(const int *beg, const int *end)
{
    for (; beg != end; ++beg)
        cout << *beg << ' ';
    cout << endl;
}

void print(const int ia[], size_t size)
{
    for (int pos = 0; pos < size; ++pos)
        cout << ia[pos] << ' ';
    cout << endl;
}

void print(int (&arr)[2])
{
    for (int pos = 0; pos < 2; ++pos)
        cout << arr[pos] << ' ';
    cout << endl;
}

void print(int (*matrix)[10], int row_size)
{
    for (int row = 0; row < row_size; ++row)
    {
        for (int col = 0; col < 10; ++col)
            cout << matrix[row][col] << ' ';

        cout << endl;
    }

    cout << endl;
}

//void print(int matrix[][10], int row_size)
//{
//    for (int row = 0; row < row_size; ++row)
//    {
//        for (int col = 0; col < 10; ++col)
//            cout << matrix[row][col] << ' ';
//
//        cout << endl;
//    }
//
//    cout << endl;
//}

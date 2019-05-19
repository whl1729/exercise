#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        cout << "Usage: ./a.out in_file out_file_1 out_file_2" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    ofstream out_odd(argv[2]);
    ofstream out_even(argv[3]);
    istream_iterator<int> in_iter(input), eof;
    ostream_iterator<int> odd_iter(out_odd, " "), even_iter(out_even, "\n");
    vector<int> ivec;

    copy(in_iter, eof, back_inserter(ivec));

    auto end_odd = partition(ivec.begin(), ivec.end(),
                             [] (const int &i) { return (i & 0x1);});

    copy(ivec.begin(), end_odd, odd_iter);
    copy(end_odd, ivec.end(), even_iter);

    input.close();
    out_odd.close();
    out_even.close();

    return 0;
}

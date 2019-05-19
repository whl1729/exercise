#include <iostream>

using namespace std;

int main()
{
    int score = 0;

    cout << "Enter your score: ";
    cin >> score;
    cout << ((score < 60) ? "fail" : ((score <= 75) ? "low pass" : (score <= 90) ? "pass" : "high pass")) << endl;

    cout << "Enter your score again: ";
    cin >> score;

    if (score < 60)
        cout << "fail" << endl;
    else if (score <= 75)
        cout << "low pass" << endl;
    else if (score <= 90)
        cout << "pass" << endl;
    else
        cout << "high pass" << endl;

    return 0;
}

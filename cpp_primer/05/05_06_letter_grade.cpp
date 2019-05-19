#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade;
    string letter_grade;

    cout << "Enter your grade: " << endl;

    while (cin >> grade)
    {
        if (grade < 60)
            letter_grade = scores[0];
        else
        {
            letter_grade = scores[(grade - 50)/10];
            if (grade != 100)
                letter_grade += ((grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "");
        }

        cout << letter_grade << endl;
    }

    return 0;
}

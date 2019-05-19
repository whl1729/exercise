#include <iostream>
#include <bitset>

using namespace std;

class Grade;

class Quiz
{
    friend class Grade;
    friend ostream &operator<<(ostream &os, const Quiz &quiz);
    friend istream &operator>>(istream &in, Quiz &quiz);
public:
    Quiz() = default;
    Quiz(unsigned u): response(u) { }
    Quiz(const string &s): response(s) { }
    void set(unsigned pos, bool val) { response.set(pos, val); }
    bool test(unsigned pos)  { return response.test(pos); }
private:
    bitset<10> response;
};

class Grade
{
    friend ostream &operator<<(ostream &os, const Grade &Grade);
    friend istream &operator>>(istream &in, Grade &Grade);
public:
    Grade(unsigned u): answer(u) { }
    Grade(const string &s): answer(s) { }
    unsigned grade(const Quiz &q);
private:
    bitset<10> answer;
};

istream &operator>>(istream &in, Quiz &quiz)
{
    in >> quiz.response;
}

unsigned Grade::grade(const Quiz &q)
{
    unsigned result = 0;
    for (unsigned pos = 0; pos < answer.size(); ++pos)
        if (answer[pos] == q.response[pos])
            ++result;
    return result;
}

ostream &operator<<(ostream &os, const Quiz &quiz)
{
    os << quiz.response;
}

int main()
{
    Quiz quiz;

    cin >> quiz;
    cout << quiz << endl;

    quiz.set(4, false);
    cout << quiz << endl;

    quiz.set(8, true);
    cout << quiz << endl;

    cout << (quiz.test(6) ? '1' : '0') << endl;

    Grade gd("1010010111");
    cout << "grade: " << gd.grade(quiz) << endl;

    return 0;
}

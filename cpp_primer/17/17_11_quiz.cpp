#include <iostream>
#include <bitset>

using namespace std;

class Quiz
{
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

istream &operator>>(istream &in, Quiz &quiz)
{
    in >> quiz.response;
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

    cout << (quiz.test(6) ? '1' : '0') << endl;

    return 0;
}

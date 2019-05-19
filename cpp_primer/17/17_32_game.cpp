#include <iostream>
#include <string>
#include <random>

using namespace std;

bool play(bool first)
{
    return false;
}

int main()
{
    string resp;
    default_random_engine eng;
    bernoulli_distribution bd;
    do
    {
        bool first = bd(eng);
        cout << (first ? "We go first" : " You get to go first") << endl;
        cout << (play(first) ? "Sorry, you lost" : "Congrats, you won") << endl;
        cout << "play again? Enter 'yes' or 'no'" << endl;
    } while (cin >> resp && resp[0] == 'y');

    return 0;
}

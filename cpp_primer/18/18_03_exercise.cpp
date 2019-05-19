#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

class Pint
{
public:
    Pint() = default;
    Pint(unsigned size): p(new int[size]) { cout << "Pint(unsigned)" << endl; }
    ~Pint() { delete p; cout << "~Pint()" << endl; }
private:
    int *p;
};

void exercise2(int *b, int *e)
{
    vector<int> v(b, e);
    Pint p(v.size());

    ifstream in("~/test/data");
    try{
        throw invalid_argument("exercise2: Nothing. Just for fun.");
    }
    catch (invalid_argument expt)
    {
        cout << expt.what() << endl;
    }
}

void exercise1(int *b, int *e)
{
    vector<int> v(b, e);
    shared_ptr<int> p(new int[v.size()]);

    ifstream in("~/test/data");
    try{
        throw invalid_argument("exercise1: Nothing. Just for fun.");
    }
    catch (invalid_argument expt)
    {
        cout << expt.what() << endl;
    }
}

void exercise0(int *b, int *e)
{
    vector<int> v(b, e);
    int *p = new int[v.size()];

    ifstream in("~/test/data");
    try{
        throw invalid_argument("exercise0: Nothing. Just for fun.");
    }
    catch (invalid_argument expt)
    {
        cout << expt.what() << endl;
    }
}

int main()
{
    int arr[] = {1,3,5,7,9};

    exercise0(arr, arr + 5);
    exercise1(arr, arr + 5);
    exercise2(arr, arr + 5);

    return 0;
}

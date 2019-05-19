#include <iostream>

using namespace std;

class Dopey
{
public:
    Dopey() { cout << "Dopey()" << endl; }
};

class Sneezy
{
public:
    Sneezy() { cout << "Sneezy()" << endl; }
    Sneezy(int i): num(i) { cout << "Sneezy(" << i << ")" << endl; }
    int get() { return num; }
private:
    int num;
};

class Bashful
{
public:
//    Bashful() { cout << "Bashful()" << endl; }
    int get() { return cnt; }
private:
    int cnt;
};

class Snow_White
{
public:
    Snow_White(): sneezy(1024) { mumble = 2048; }
    Bashful bashful;
    Dopey dopey;
    Sneezy sneezy;
    int get() { return mumble; }
private:
    int mumble;
};

int main()
{
    Snow_White sw;
    cout << "mumble: " << sw.get() << endl;
    cout << "sneezy.num: " << sw.sneezy.get() << endl;
    cout << "Bashful.cnt: " << sw.bashful.get() << endl;

    return 0;
}

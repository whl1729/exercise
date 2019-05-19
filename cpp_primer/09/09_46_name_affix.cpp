#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name, prefix, suffix;

    cout << "Enter a name, prefix and suffix: " << endl;
    cin >> name >> prefix >> suffix;

    name.insert(0, prefix);
    name.insert(name.size(), suffix);

    cout << name << endl;

    return 0;
}

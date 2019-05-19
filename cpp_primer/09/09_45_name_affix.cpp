#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name, prefix, suffix;

    cout << "Enter a name, prefix and suffix: " << endl;
    cin >> name >> prefix >> suffix;

    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(suffix.begin(), suffix.end());

    cout << name << endl;

    return 0;
}

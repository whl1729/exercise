#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " number" << endl;
        return 1;
    }

    cout << "The square root of " << argv[1] << " is "
         << sqrt(stod(argv[1])) << endl;

    return 0;
}

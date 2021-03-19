#include <iostream>
#include "step5_config.h"

#ifdef USE_MYMATH
#include "math_functions.h"
#else
#include <cmath>
#endif

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " number" << endl;
        return 1;
    }

    const double input = stod(argv[1]);

#ifdef USE_MYMATH
    const double output = mysqrt(input);
#else
    const double output = sqrt(input);
#endif

    cout << "The squre root of " << input << " is " << output << endl;
    return 0;
}

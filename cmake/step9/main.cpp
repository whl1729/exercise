#include <iostream>
#include "step9_config.h"
#include "math_functions.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    const double input = std::stod(argv[1]);

    const double output = mathfunctions::sqrt(input);

    std::cout << "The squre root of " << input << " is " << output << std::endl;
    return 0;
}

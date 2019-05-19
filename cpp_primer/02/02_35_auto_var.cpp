#include <iostream>

int main()
{
    const int i = 42;
    auto j = i;  // int
    const auto &k = i;  // const int &
    auto *p = &i;  // const int *
    const auto j2 = i, &k2 = i;  // const int, const int &
    auto &v = i;  // const int &

    std::cout << "i=" << i << " j=" << j << " k=" << k << std::endl;
    std::cout << "p=" << p << " j2=" << j2 << " k2=" << k2 << std::endl;
    std::cout << "v=" << v << std::endl;

    j = 24;
    k = 24;
    *p = 24;
    j2 = 24;
    k2 = 24;
    v = 24;

    std::cout << "i=" << i << " j=" << j << " k=" << k << std::endl;
    std::cout << "p=" << p << " j2=" << j2 << " k2=" << k2 << std::endl;
    std::cout << "v=" << v << std::endl;

    return 0;
}

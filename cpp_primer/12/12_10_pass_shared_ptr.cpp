#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> spi)
{
    cout << "Inside process, spi's use count: " << spi.use_count() << endl;
}

int main()
{
    shared_ptr<int> spi(new int(1024));
    cout << "spi's use count: " << spi.use_count() << endl;

    process(shared_ptr<int>(spi));
    cout << "spi's use count: " << spi.use_count() << endl;
    cout << "*spi=" << *spi << endl;

    auto q = spi;
    cout << "spi's use count: " << spi.use_count() << endl;
    cout << "*spi=" << *spi << endl;

    return 0;
}

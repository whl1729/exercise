#include <iostream>
#include <thread>

using namespace std;

void Foo()
{
    cout << "Hello World" << endl;
}

void Bar(int num)
{
    cout << "I have got " << num << " offers." << endl;
}

int main()
{
    thread apple;
    thread cat{Foo};
    thread dog{Bar, 10};
    cout << "dog's id: " << dog.get_id() << endl;
    thread egg{std::move(dog)};

    cout << boolalpha;
    cout << "Is apple joinable? " << apple.joinable() << endl;
    //apple.join();
    cout << "Is apple joinable? " << apple.joinable() << endl;
    cout << "apple's id: " << apple.get_id() << endl;

    cout << "Is cat joinable?" << cat.joinable() << endl;
    cout << "cat's id: " << cat.get_id() << endl;
    cout << "dog's id: " << dog.get_id() << endl;
    cout << "egg's id: " << egg.get_id() << endl;
    cat.join();
    cout << "Is cat joinable?" << cat.joinable() << endl;

    //dog.join();
    egg.join();
    //cout << "Is dog joinable? " << dog.joinable() << endl;
    cout << "Is egg joinable?" << egg.joinable() << endl;
    cout << noboolalpha;

    cout << "hardware_concurrency: " << thread::hardware_concurrency() << endl;

    cout << "cat's id: " << cat.get_id() << endl;

    cout << "apple detach" << endl;
    //apple.detach();
    cout << "cat detach" << endl;
    //cat.detach();

    return 0;
}

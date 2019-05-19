#include <iostream>
#include "Message.h"
#include "Folder.h"

int main()
{
    Message m1("day after day");
    Message m2("ocean's apart");
    Message m3("say goodbye");

    Folder f1("/bin");
    Folder f2("/home");
    Folder f3("/usr");

    m1.save(f1);
    m1.save(f2);
    m2.save(f2);
    m2.save(f3);
    m3.save(f3);
    m3.save(f1);

    m1.print();
    m2.print();
    m3.print();
    f1.print();
    f2.print();
    f3.print();

    return 0;
}

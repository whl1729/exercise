#include <iostream>
#include <vector>
#include "Employee.h"

using namespace std;

int main()
{
    vector<Employee> huawei(10);

    for (auto &h : huawei)
        h.print();

    Employee e("David");
    e.print();
//    vector<Employee> tencent(10, Employee("hello"));
//
//    for (auto &t : tencent)
//        t.print();

    return 0;
}

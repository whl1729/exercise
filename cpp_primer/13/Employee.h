#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

using std::string;
using std::cout;
using std::endl;

class Employee
{
public:
    Employee()  { id = ++cnt; }
    Employee(const string &n)  { name = n; id = ++cnt; } 
    Employee(const Employee &e) = delete; 
    Employee& operator=(const Employee &e) = delete;
    
    void print() const;

private:
    string name;
    int id;
    static int cnt;
};

void Employee::print() const
{
    cout << "name: " << name << ", id: " << id << endl;
}

int Employee::cnt = 0;

#endif

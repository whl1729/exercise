class Base
{
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

class Pub_Derv : public Base
{
    int f() { return prot_mem; }
    // error: ‘char Base::priv_mem’ is private within this context
    char g() { return priv_mem; }
};

class Prot_Derv : protected Base
{
    int f2() const { return prot_mem; }
};

class Priv_Derv : private Base
{
    int f1() const { return prot_mem; }
};

struct Derived_from_Pub : public Pub_Derv
{
    int use_base() { return prot_mem; }
};

struct Derived_from_Prot : public Prot_Derv
{
    int use_base() { return prot_mem; }
};

struct Derived_from_Priv : public Priv_Derv
{
    int use_base() { return prot_mem; }
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Pub dd1;
    Derived_from_Priv dd2;
    Derived_from_Prot dd3;
    Base *p = &d1;
    p = &dd1;
    // error: ‘Base’ is an inaccessible base of ‘Priv_Derv’
    p = &d2;
    // error: ‘Base’ is an inaccessible base of ‘Prot_Derv’
    p = &d3;
    // error: ‘Base’ is an inaccessible base of ‘Derived_from_Priv’
    p = &dd2;
    // error: ‘Base’ is an inaccessible base of ‘Derived_from_Prot’
    p = &dd3;

    return 0;
}

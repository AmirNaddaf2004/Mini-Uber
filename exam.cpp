#include <iostream>

using namespace std;

class superbase
{
public:
    void f() { cout << 1; }
    virtual void g() { cout << 2; }
    void h() { g(); }
};

class base : public superbase
{
public:
    virtual void g() { cout << 3; }
};

class derived : public base
{
public:
    void f() { cout << 4; }
};

int main()
{
    superbase s;
    base b;
    derived d;
    superbase *p;
    p = &s;
    p->f(); //1 2 2
    p->g();
    p->h();
    cout << "goooz" << endl;
    p = &b;
    p->f(); //1 3 3
    p->g();
    p->h();
    cout << "chos" << endl;
    p = &d; //1 3 3
    p->f();
    p->g();
    p->h();
}
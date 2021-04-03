// dynamicLinkage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;
class A {
    int id_;
public:
    A(int id) :id_{ id } {};
    int get_id() { return id_; }
    virtual void foo() { cout << "A's foo ID "<<id_<< endl; }
};
class B :public A {
    int age_;
public:
    B(int id, int age) :A{ id }, age_{ age }{};
    int get_age() { return age_; }
    void foo()override { cout << "B's foo ID is " <<this->get_id()<<endl; }
    virtual void bar() { cout << "B's Bar age is " << age_ << endl; }
};
class C : public B {
    int exp_;
public:
    C(int id, int age, int exp) :B{ id,age }, exp_{ exp }{};
    void bar() override{ cout << "C's bar age is "<<this->get_age() << endl; }
    void widget() { cout<<"C's widget Experience is "<<exp_<<endl;}
};

class D : public B {
public:
    D(int id, int age) :B{ id,age } {};
    void bar() override { cout << "D's bar" << endl; }
};

template<typename T>
void minmax(T& x, T& y) {
    if (x > y) {
        T tmp = move(x);
        x = move(y);
        y = move(tmp);
    }
}

int main()
{
    vector<A*>Nodes;
    Nodes.push_back(new A(1));
    Nodes.push_back(new B(2,22));
    Nodes.push_back(new C(3,33,7));
    Nodes.push_back(new D(4,34));
    int id = 0;
    for (auto& a : Nodes) {
        cout << "###########" << a->get_id() << endl;
        a->foo();
        B* p = dynamic_cast<B*>(a);
        if (p)
            p->bar();
        C* q = dynamic_cast<C*>(a);
        if (q)
            q->widget();
        id++;
    }
    int x=200, y=100;
    minmax(x, y);
    double dx = 100.43, dy = 100.21;
    minmax(dx, dy);
}

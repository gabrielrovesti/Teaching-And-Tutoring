#include <iostream>

class A{
    public:
    virtual ~A() = default;
};

class B: public A{
    public:
    virtual void metodo() = 0;
};

class C: public B{
    public:
    void metodo(){return;}
};

class D{
    private:
    int num;
    protected:
    D(int n): num(n) {}
};

class E: virtual public D{
    private:
    int number;
    public:
    E& operator=(const E& e){
        D::operator=(e);
        number = e.number;
        return *this;
    }
};
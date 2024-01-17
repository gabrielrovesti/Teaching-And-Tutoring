class A{
    public:
    virtual ~A()
};

class B : virtual public A {
    public:
    virtual void f() const = 0;
};

class C : public B {
    public:
    void f() const {}
};

class D : virtual public A {
    private:
        int x;
    protected:
        D(int x1): x(x1) {};
}

class E : public C, public D {
    private:
        int x;
    public:
        E& operator=(const E& e){
            C::operator=(e);
            D::operator=(e);

            x = e.x;

            return *this;

        }
}
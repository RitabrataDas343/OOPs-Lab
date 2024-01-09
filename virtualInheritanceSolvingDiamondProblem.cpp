// illustrating solution to the diamond problem in multiple inheritance using virtual base classes


#include<iostream>

using namespace std;


class A  // root-base
{ public: int a;
  A(int x=5) : a(x) { cout<<"A(int)"<<a<<endl; }
  ~A() { cout<<"~A()"<<endl; }
};

class B1 :  virtual public A // virtual base class
{ public: int b1;
   B1(int y=10) : A(y), b1(y) { cout<<"B1(int)"<<b1<<endl; }
  ~B1() { cout<<"~B1()"<<endl; }
};   

class B2 :  virtual public A // virtual base class
{ public: int b2;
   B2(int z=15) : A(z), b2(z) { cout<<"B2(int)"<<b2<<endl; }
  ~B2() { cout<<"~B2()"<<endl; }
};   

class D : public B1, public B2  // derived
{ // inherits B1::fx(int) , B2::fx(void)
  public: int d;
   D(int p=1, int q=2, int r=3, int s=4) : B2(q), B1(p), d(r), A(s)
    {  
      cout<<"D(int)"<<a<<b1<<b2<<d<<endl; 
    }
  ~D() { cout<<"~D()"<<endl; }
  
}; 

int main()
{
  D d;

  A  *p=new D;

}
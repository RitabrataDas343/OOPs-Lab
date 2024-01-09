// illustrating function overloading overriding and adding in multiple Inheritance


#include<iostream>

using namespace std;

class B1  // base1
{ public: 
  void fx(int) { cout<<"B1::fx(int)"<<endl; }
  void gx(int) { cout<<"B1::gx(int)"<<endl; }
  void hx(int) { cout<<"B1::hx(int)"<<endl; }
  
};   

class B2  // base2
{ public: 
   void fx(void) { cout<<"B2::f1()"<<endl; }
   void gx(int) { cout<<"B2::gx(int)"<<endl; }
   void hx(int) { cout<<"B2::hx(int)"<<endl; }
}; 

class D : public B1, public B2  // derived
{ // inherits B1::fx(int) , B2::fx(void)
  public: 
  using B1::fx;
  void gx(void) { cout<<"D::gx()"<<endl; }    // overloads
  void hx(int) { cout<<"D::hx(int)"<<endl; }  // overrides
  void kx(int) { cout<<"D::kx(int)"<<endl; }  // adds
}; 

int main()
{
  D d;

  //d.B1::fx(5);  // error: request for member ‘fx’ is ambiguous, can't resolve overloaded calls across two different namespaces B1, B2
  //d.B2::fx();  //   error: request for member ‘fx’ is ambiguous
  d.fx(4);
  d.B2::fx();
  d.gx();
  d.B1::gx(5);
  d.B2::gx(7);
  d.hx(1);
  d.B1::hx(8);
  d.B2::hx(8);
  d.kx(9);
}

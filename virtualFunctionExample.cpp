// illustrating static/dynamic function binding and use of virtual functions

#include<iostream>

using namespace std;

class B 
{ public: 
  virtual void fn(void) 
  {cout<<"B::fn()"<<endl;}
  void gn(void) 
  {cout<<"B::gn()"<<endl;}
};   // 
class D : public B 
{ public:
  void fn(void) // overridden 
  { cout<<"D::fn()"<<endl;
  }
  void hn(void)  // new added
  {cout<<"D::hn()"<<endl;
  }
}; 
int main()
{
  D d;
  d.fn(); d.gn(); d.hn();

  B  &rd=d;  // upcast
  rd.fn(); rd.gn(); //rd.hn();

  B *pd=&d; // upcast
  pd->fn(); pd->gn(); //pd->hn();
}

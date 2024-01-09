// illustrating publicizing privately inherited members in derived class

#include<iostream>

using namespace std;

class B 
{ public: int b1; 
  B(int x=1): b1(x){}
  ~B(){}
};   // 
class D : public B 
{ public: int d1;
  D(int x=5, int y=10): B(x), d1(y){}
  ~D(){}

}; // 

int main()
{
  B b(2);
  D d(4,6);

  B *pb=&b;
  D *pd=&d;
  
  cout<<pb->b1<<endl;
  cout<<pd->b1<<"  "<<pd->d1<<endl;

  pb=pd;  // works fine;  Upcasting
  cout<<pb->b1<<endl;
  //pd=pb;  //  error: invalid conversion from ‘B*’ to ‘D*’; Downcasting not allowed


  void *pv=NULL;
  pv=pb;  // works; looses type due to casting
  pv=pd;  // works; looses type due to casting
  
  //pb=pv;  //  error: invalid conversion from ‘void*’ to ‘B*’
  //pd=pv;  //  error: invalid conversion from ‘void*’ to ‘B*’
}

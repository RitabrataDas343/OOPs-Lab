// illustrating the use of virtual destructor to avoid object-slicing (can be observed if you make base destructor non-virtual)

#include<iostream>

using namespace std;

class B
{ int  b1;
  public:  
    B(int x): b1(x) { cout<<"B()"<<endl; }
    virtual ~B(){ cout<<"~B()"<<endl; }
     void display(void) {  cout<<b1<<endl; }
};

class D : public B
{ int *p;
  public:
    D(int x, int y): B(x), p(new int(y)) { cout<<"D()"<<endl; }
    ~D(){ cout<<"~D()"<<endl; delete p; }
    void display(void) {  B::display(); cout<<"  "<<*p<<endl; }
};

int  main(void)
{
   B *ptrBase = new D(2,4); // upcasting
  
   cout<<sizeof(B)<<"....."<<sizeof(D)<<endl;
   ptrBase->display(); // ????

   delete ptrBase;
}








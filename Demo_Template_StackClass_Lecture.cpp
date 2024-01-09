#include<iostream> 
#include<iomanip>
using namespace std; 


template  <class T, int t=5>
class stack
{
   //  member data
   private:
      T  *a; /////////
      int top,size;
   public:
      int  n;

   //  member methods
   private:
      int isempty(void);
      int isfull(void);

   public:
      stack(int x=t);
     ~stack();
     int push(T x);  /////////
      T pop(void);    ///////
      void display(void);
     
};  // end of class stack

//  definition of the member methods
template  <class T, int t>
      int stack<T,t>::isempty(void)
      {
         return(top==-1);
      }

template  <class T, int t>
      int stack<T,t>::isfull(void)
      {
         return(top==(size-1));
      }

template  <class T, int t>
   stack<T,t>::stack(int x)
   {
      cout<<"Contr"<<endl;
      size=x;  a=new T[size];  ////////
      top=-1; n=-1;  
   }

template  <class T, int t>
   stack<T,t>::~stack()
   {
      cout<<"Destr"<<endl;
      delete [] a;
   }

template  <class T, int t>
   int stack<T,t>::push(T x)  /////
   {
      if(!isfull())
         {
            a[++top]=x;  n++;
            return(1);
         }
      else
         {  cout<<"Stack overflow"<<endl;
            return(-1);
         }
   }
template  <class T, int t>
   T stack<T,t>::pop(void)  ///////
   {
      if(!isempty())
         {
            T x=a[top--]; n--;  /////
            return(x);
         }
      else
         {  cout<<"Stack underflow"<<endl;
            return(-1);
         }
   }

template  <class T, int t>
   void stack<T,t>::display(void)
   {  
      cout<<"Displaying Stack ::"<<endl;
      cout<<"     |    | "<<endl;
      for(int i=top;i>=0;i--)
         {
            cout<<"     | "<<a[i]<<" | "<<endl;
            cout<<"     |__"<<"__| "<<endl;  
         }
         cout<<"//////////////////"<<endl;
   }

int main(void) 
{ 
     stack<int,3> *p; // will not attempt to craete an instance of the template class

     stack<int,2> s1;  //  one instance of the template class and one instance of the class is create
     stack<float,5> sf;   //  ???
     stack<char,10>  sc(4),ss(9); //  ???

     s1.push(10);
     sf.push(20.5);
     s1.display();
     {
        stack<int> s2(4);
     }
     s1.push(30);
     cout<<s1.pop()<<" "<<s1.pop()<<endl;
     s1.pop();
     
} 
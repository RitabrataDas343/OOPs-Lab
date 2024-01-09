// illustrating pure virtual function and abstract base class using employee class hierarchy


#include<iostream>

using namespace std;

class employee   // abstract base class
{ int  empId;
  public:  virtual void dispLeave () = 0 ;// pure virtual function
};
void employee::dispLeave()  // defining the body of a pure virtual function
{  cout<<"NationalHol, CasualL"; }
//------------------------------------------------
class permanent : public employee    // abstract base class
{ 
  // inherits dispLeave as pure virtual function
};

//--------------------------------------------------------------
class temporary : public employee    // concrete class
{  
   public:  void dispLeave(void) 
   {  cout<<"Temp-Staff : NationalHol, CasualL"; }
};
//-----------------------------------------------------------
class staff : public permanent    // concrete class
{ 
  public:  void dispLeave(void) 
  { cout<<"Per-Staff: EarnedL, MedicalL,, NationalHol, CasualL";  }
};
class faculty : public permanent    // concrete class
{ 
  public:  void dispLeave(void) 
  {  cout<<"Per-Faculty: VacationL, EarnedL, MedicalL,, NationalHol, CasualL";  }
};



int  main(void)
{
   employee *arr[] = {new faculty, new faculty, new staff,  new staff,  new temporary};
   //employee a;
   //permanent  p;

   for(int  i=0;i<(sizeof(arr)/sizeof(employee*));i++)
      {
        cout<<"Emp "<<i+1<<" : ";arr[i]->dispLeave(); cout<<endl;
      }
}

#include"MyLinkedList.h"
#include<iostream> 
#include<iomanip>
using namespace std; 

/////////////////////////  hash table class definition /////////////////////
class hashing
{
    sll *ht;
    int  htsize;

    int hashfn(int x);

    //  public members
    public:

      hashing(int);
      ~hashing();
      int searchhs(int);
      void inserths(int);
      int delhs(int);
      void display(void);
};

  int hashing::hashfn(int x)
  {
      return(x%htsize);
  }
  hashing::hashing(int n=10)
  {
      cout<<" Hash table constructor "<<endl;
      ht=new sll[n];
      htsize=n;
  }
  hashing::~hashing()
  {
    cout<<" Hash table destructor "<<endl;
    /*for(int i=0;i<htsize;i++)
      {
        ht[i].delsll();
      }*/
      
    delete []ht;
    
  }
  int hashing::delhs(int x)
  {
      int b=hashfn(x);
      if(ht[b].search(x)!=NULL)
        return(ht[b].delnode(x));
      else
        return 0;
  }
  void hashing::inserths(int x)
  {
    int b=hashfn(x);
    ht[b].addbeg(x);
  }
  int hashing::searchhs(int x)
  {
      int b=hashfn(x);
      node *t=ht[b].search(x);
      if(t!=NULL)
       {
        cout<<" Found in hash table:"<<t->info<<" "<<t->extra<<endl;
        return 1;
       } 
      else
        {
          cout<<x<<" Not Found in hash table:"<<endl;
          return 0;
        }
  }

  void hashing::display(void)
  {
      cout<<" Displaying Hash table"<<endl;
      for(int i=0;i<htsize;i++)
          ht[i].display();    
  }


///////////////////////   END of hash table class definition /////////////////////
int main(void)
{ 
      hashing h1;
      //h1.display();
      h1.inserths(15);
      h1.inserths(22);
      h1.inserths(72);
      h1.display();
      h1.delhs(15);
      h1.display();

}
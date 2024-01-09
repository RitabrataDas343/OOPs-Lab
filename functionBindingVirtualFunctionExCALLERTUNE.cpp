// illustrating static/dynamic function binding and use of virtual functions

#include<iostream>

using namespace std;

enum  track {A, B, C};
class Instr
{
  public:  
    virtual void  play(track t)
    {
      cout<<"Instr::play"<<endl;
    }
};

class Guitar : public Instr
{
  public:
  void  play(track t)
    {
      cout<<"Guitar::play"<<endl;
    }
};

void callerTune(Instr &i, track r)
{   i.play(r);   }   

void callerTune(Instr *p, track r)
{   p->play(r);   }  

void guitarTune(Guitar &x, track r)
{   x.play(r);   }  

void guitarTune(Guitar *x, track r)
{   x->play(r);   }  




int main()
{
   Instr  s;
   Guitar  g;

   callerTune(s,B);
   callerTune(g,C);  // upcasting

   callerTune(&s,B);
   callerTune(&g,C);  // upcasting

   //guitarTune(s,B);  // downcasting not allowed
   guitarTune(g,C);  

   //guitarTune(&s,B);  // downcasting not allowed
   guitarTune(&g,C);  

}

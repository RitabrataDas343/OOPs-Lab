
#include<iostream> 
#include<iomanip>
using namespace std; 

/////////////////////////  node class definition /////////////////////
class node
{
   //  member data
   public:
      int  info;  // value to be stored
      int  extra;
      node *link;  // points to any node of it's type
      // self-referential

   //  member methods
   public:  // public interface
      node(int,node *,int);
      ~node();
      void display(void );
};  // end of node class interface

  node::node(int v=0, node *l=NULL, int e=0)
      {
        //cout<<" node contr"<<endl;
        info=v; link=l; extra=e;
      }
 node::~node()
      {
        cout<<" node destr"<<endl;
      } 
       
  void node::display(void)
      {
        cout<<" node::"<<info<<" " <<extra<<" "<<link<<endl;
      }   

          
/////////////////////////  END of node class definition /////////////////////


/////////////////////////  singly linked list class definition /////////////////////
class sll
{
   //  member data
   private:
    // header node it stores node cnt & link to the 1st node
      node  head; 

   //  member methods
   public:  // public interface
      sll(node *,int);
      sll(const sll &);
      ~sll();
      void addbeg(int x);
      void display(void);
      node *search(int x);
      int delnode(int x);
      void delsll(void);
};  // end of node class interface

  sll::sll(node *l=NULL,int e=0)
  {
      cout<<" sll constructor"<<endl;
      head.info=0; head.link=l; head.extra=e;
      if(l!=NULL) // given an existing chain of nodes 
      {
        // find the number of nodes in that chain
        int cnt=1;  node *t=l;
        while(t->link!=NULL)
        {
          t=t->link; cnt++;
        }
        head.info=cnt;
      }
  }

  sll::sll(const sll &s)
  {
      cout<<" Copy Contr"<<endl;
      head.info=s.head.info;
      node *t;
      const node *c=s.head.link;
      for(int i=0;i<(s.head.info);i++)
      {
          node *n=new node(c->info,NULL);
          if(i==0)
          {
              head.link=n; t=n; 
          }
          else
          {
              t->link=n; t=n;
          }
          c=c->link;
      }
  }

  sll::~sll()
  {
      node *t;
      cout<<" sll destructor "<<head.info<<endl;
      delsll();
      cout<<" sll destroyed "<<endl;
  }
  void sll::delsll(void)
  {
      node *t;
      for(int i=0;i<(head.info);i++)
      {
          t=head.link;
          head.link=(head.link)->link;
          //cout<<t->info<<"  ";
          delete  t;
      }
  }

  void sll::addbeg(int x)
  {  
      head.link=new node(x,head.link);
      head.info++;
  }

  void sll::display(void)
  {
      node *t=head.link;
      cout<<" displaying linked list : ";
      cout<<"||"<<head.info<<" nodes||"<<"----";
      for(int i=0;i<head.info;i++)
      {
          cout<<">|"<<t->info<<"|----";
          t=t->link;
      }
      cout<<"XXXX"<<endl;
  }

  node *sll::search(int x)
  {
      node *t=head.link;
      for(int i=0;i<head.info;i++)
      {
          if(t->info==x)
            return t;
          else
            t=t->link;
      }
      return NULL;
  }

  int sll::delnode(int x)
  {
     node *t=&head;  // to enable lookahead
      for(int i=0;i<head.info;i++)
      {
          if(t->link->info==x)
            {
              node *p=t->link;
              t->link=t->link->link;
              delete p;  
              (head.info)--;
              return 1;
            }
          else
            t=t->link;
      }
      return 0;
  }

///////////////////////   END of linked list class definition /////////////////////
/*int main(void)
{ 
     node  x;
     node   y(20);
     node   z(30,&x);
     node  *p=new node();
     node  *q=new node(y);
     x.display();
     y.display();
     z.display();
     q->display();
     
  

      sll  s4;
      s4.addbeg(100);
      s4.display();

      sll  s1;
      for(int i=0;i<5;i++)
        s1.addbeg(i+5);
      s1.display();

      cout<<"Deletetion "<<s1.delnode(6)<<endl;
      s1.display();

      sll  s2(s1);
      s2.display();
      cout<<"Deletetion "<<s2.delnode(8)<<endl;
      s2.display();
}
*/
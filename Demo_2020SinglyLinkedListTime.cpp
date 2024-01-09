#include<iostream>
#include <chrono>
using namespace std::chrono;  
#include "sllnodeAvail.h"
//#include"sllnodeWithoutAvail.h"
using namespace std;


//.......................................................
class  sll
{
    sllnode   *sllHead;  //  head pointer pointing to the sll nodes
    public:  int    nodeCnt;  // keep track of current node count

    sll(sllnode *p=NULL)
    {
    	cout<<"constructing sll "<<endl;
    	sllHead=p; nodeCnt=0;
    }
    ~sll()
    {
    	cout<<"destroying sll "<<endl;
    	//   deallocate/free one-by-one all nodes pointed by sllHead
    	while(sllHead!=NULL)
    	{
    		sllnode *temp=sllHead;  sllHead=sllHead->next;
    		//cout<<temp->val<<"  ";
    		delete  temp;
    	}
    	nodeCnt=0;

    }
    
    

   // other method/ friend function prototypes

    friend int  operator+(int x, sll  &list); // 3 + a  => overloads binary +; implies add an interger at the begining of sll a; returns 1 if successful else -1
    friend int operator-(sll  &list); // - a  => overloads unary -; implies delete a node from the begining of sll a; returns the delted node info
    friend ostream & operator<<(ostream &x, const sll &list); // cout<<a => overloades the << operator; displays the object a

};  // End of sll class

//////Method definitions


 

// 3 + a  => overloads binary +; implies add an interger at the begining of sll a; returns 1 if successful else -1
int operator+(int x, sll  &list)
{
	//cout<<"opeartor binary + overload "<<endl;
	list.sllHead=new sllnode(x, list.sllHead);  // new node points to the prev 1st and new created node becomes the 1st node pointed by sll head
	list.nodeCnt++;
	return 1;
}

// - a  => overloads unary -; implies delete a node from the begining of sll a; returns the delted node info
int operator-(sll  &list)
{
    //cout<<"opeartor unary - overload "<<endl;
    sllnode  *temp=list.sllHead; 
    int  info=temp->val;
    list.sllHead=list.sllHead->next;
    list.nodeCnt--;
    delete temp;
    return info;
}




// cout<<a => overloades the << operator; displays the object a
ostream &operator<<(ostream &x, const sll  &list)
{
	sllnode   *temp=list.sllHead;
	x<<"displaying singly linear linked list: "<<endl;
	x<<"head ---";
	while(temp!=NULL)
	{
		cout<<">["<<temp->val<<", --]---";
		temp=temp->next;
	}
	cout<<"///"<<endl;

	return x;
}

//..........................................................
int main()
{
	auto start = high_resolution_clock::now();  // Get starting timepoint 
   {
   	sll  a;

     for(int i=0;i<200000000;i++)
     	i+a;
   //cout<<a<<endl;
  }

  {
  	sll b;

  for(int i=0;i<200000000;i++)
     	i+b;
  //cout<<b;
  }

  auto stop = high_resolution_clock::now();  // Get ending timepoint 

  auto duration = duration_cast<microseconds>(stop - start);  // Get duration and proper typecasted
  cout << "Time taken by program: "<< duration.count()/1000000 << " seconds" << endl; 
   
   return 0;
}  
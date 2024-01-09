// illustrating the use of global new/delete opeartor; 
// examples of int, float (as buitl-in types) and complex (as user-defined type) class has been considered

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void  *operator new(size_t sz)
{
	printf("\n\tGlobal Overloaded new; size: %d bytes\n",(int)sz);
	void *x;
	x=malloc(sz);
    if(!x)
    	printf("\n\t Out of memory");  // you may throw an exception here

    return x;
}

void operator delete(void *x)
{
	printf("\n\tGlobal Overloaded delete");
	//*(int*)x=0; // resets the contents of the allocated space
	if(!x)
		free(x);
}


class complex
{
   	float rl, img;

	public:

		complex(float f1=1.0,float f2=1.0)
		{
			cout<<"Complex Object Constructor"<<endl;
			rl=f1; img=f2;
		}
		~complex()
		{
			cout<<"Complex Object Destructor"<<endl;
		}


};


//..........................................................
int main()
{
	
   int *a=new int;
   delete a;

   int *b=new int[2];
   delete b;
   
   complex *c=new complex;
   delete c;
   

   complex *d=new complex[2];  //  extra bytes of memory is allocated to store information (inside the array) about the number of objects it holds
   delete []d;


   return 0;
}
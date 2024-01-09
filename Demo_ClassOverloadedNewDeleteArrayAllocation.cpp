// illustrating the use of new/delete operator for a class; 
// examples to show that int (buitl-in types) still call the default global  new/delete
// however when a single complex (user-defined type) class object is craeted in heap it uses the overloaded new/delete member function
// and for an array of complex object also it uses the overloaded new[]/delete[] member function

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

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

//............for dy allocating single object
	void  *operator new(size_t sz)
	{
	printf("\n\tComplex Overloaded new; size: %d bytes\n",(int)sz);

	void *x;
	x=malloc(sz);
    if(!x)
    	printf("\n\t Out of memory");  // you may throw an exception here

    return x;
	}

//............for dy allocating an array of object
	void  *operator new[](size_t sz)
	{
	printf("\n\tComplex Overloaded new for array; size: %d bytes\n",(int)sz);

	void *x;
	x=malloc(sz);
    if(!x)
    	printf("\n\t Out of memory");  // you may throw an exception here

    return x;
	}

//............for deallocating a single dy allocated object
	void operator delete(void *x)
	{
	printf("\n\tComplex Overloaded delete\n");
	if(!x)
		free(x);
	}

//............for deallocating an array of dy allocated objects
	void operator delete[](void *x)
	{
	printf("\n\tComplex Overloaded delete for arrays\n");
	if(!x)
		free(x);
	}


}; // End of class complex


//..........................................................
int main()
{
   int *a=new int;   // uses the deafult new operator
   delete a;        // uses the deafult delete operator
   
   complex *c=new complex;   // calls the operator new member function
   delete c;			// calls the operator delete member function
   

   complex *d=new complex[2];  // calls the operator new[] member function
   delete []d;       // calls the operator delete[] member function


   return 0;
}
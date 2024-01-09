#include <iostream>
using namespace std;

// generic programming using macrp
#define max(x,y)    (x>y) ? x : y

// generic programming using templates
template <class Z, class T>
void  maxFunc(Z x, T y)
{
	cout<<((x>y) ? x : y)<<endl;
	return ;
}


void bubblesort(int *a, int n)
{
	int i, j;
	//bubble sort algorithm
	cout<<" Integer bubble sort"<<endl;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int x;
				x=a[i]; a[i]=a[j]; a[j]=x;
			}
		}
}

template<class T>
void bubblesort(T *a, int n)
{
	int i, j;
	//bubble sort algorithm
	cout<<" Template bubble sort"<<endl;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				T x;
				x=a[i]; a[i]=a[j]; a[j]=x;
			}
		}
}


int main(void) 
{
	int a=5,b=6;
	float  f1=2.3, f2=5.6;

	maxFunc(a,b);
	maxFunc(f1,f2);
	maxFunc(a,f2);
	maxFunc(a++,b++);
	cout<<a<<b<<endl;

	int  arrint[5]={20,6,78,0,12};
	float  arrfloat[5]={20.7,6.4,78.9,0.5,12.2};
	char   arrchar[5]={'e','o','a','i','u'};

	//call to bubble for inter sorting
	bubblesort(arrint,5);  cout<<"Sorted array"<<endl;
	for(int i=0;i<5;i++)
		cout<<arrint[i]<<"  ";

	bubblesort(arrfloat,5);  cout<<"Sorted array"<<endl;
	for(int i=0;i<5;i++)
		cout<<arrfloat[i]<<"  ";

    bubblesort(arrchar,5);  cout<<"Sorted array"<<endl;
	for(int i=0;i<5;i++)
		cout<<arrchar[i]<<"  ";
	

	return 0;
}

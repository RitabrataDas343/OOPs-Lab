// Temp Convertion Far to Cent
// The 1st C++ code
#include<iostream>
using namespace std; 

int main(void)
{
	int  far;
	char c;

    do{
    	cout<<"Enter farenheit ";
		cin>>far;

    	// conversion formula
		float  cen=(float)(far-32)*(5.0/9);

		cout<<far<<" far= "<<cen<<" cen"<<endl;

		cout<<"Do you want to continue ?"; 
		fflush(stdin);  cin>>c; 
		
	}while((c=='y')||(c=='Y'));

    //return(0);
}


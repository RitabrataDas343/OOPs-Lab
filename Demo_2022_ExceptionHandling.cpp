#include<iostream> 
#include<iomanip>
using namespace std; 

float flexp;
int   intexp;
char  charexp;

class circle
{
	float r;

	public: 
	circle(int x) 
	{cout<<"constr"; r=x;}

	~circle() { cout<<"destr"<<endl;} 

	float area(void)
	{
		if(r==0)  
			throw flexp;
        if(r<0)  
			throw intexp;
		if(r==1)
			throw charexp;

		return (3.14*r*r);
	}
};


int  main(void)
{
	float a;
	cout<<"Enter the radius of the circle :";
	cin>>a;

	circle  c1(a),c2(10);

	try{

		float  val=c1.area();
		cout<<"The area is: "<<val<<endl;

	   }

    catch(float)
    {
    	//if(f==-1)
    		cout<<"ERROR: not a circle ";
		 	//cout<<"actually a point"<<endl; //exit(1);
    }
    catch(...)
    {
        //if(f==-2)
    		cout<<"ERROR";
		 	//cout<<endl; //exit(1);
		 
	}
	

}







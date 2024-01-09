#include<iostream> 
#include<iomanip>
using namespace std; 


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
			throw (-1.0);
        if(r<0)  
			throw (-2.0);

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

    catch(...)
    {
    	//if(f==-1)
    		{cout<<"ERROR: ";
		 	//cout<<"actually a point"<<endl; //exit(1);
		 }
    	//if(f==-2)
    		//{cout<<"ERROR: Neg radius absurd";
		 	//cout<<endl; //exit(1);
		 //}
	}

	cout<<"Bye"<<endl;
	

}
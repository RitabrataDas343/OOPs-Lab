#include <iostream>
using namespace std;

class Salary{
	double basic;
	double gross;
	public:
		static double da;
		const double bonus;
		Salary(double , const double );
		static void dahike(double );
		void calc_salary();
		void display();		
};

Salary:: Salary(double a, const double b): bonus(b){
	basic=a;
}

double Salary::da=7;

void Salary:: calc_salary(){
	double d= (basic*da)/100;
	gross = bonus + basic +d;
}

void Salary::display(){
	cout << "The Salary of the employee= " << gross << endl;
}

void Salary::dahike(double d){
	Salary::da=d;
}

int main(){
	double a=0.0, b=0.0;
	cout << "Give the basic pay of Employee= ";
	cin >> a;
	cout << "Give the bonus for the Employee= ";
	cin >> b;
	Salary s(a, b);
	s.calc_salary();
	s.display();
	cout << "Give the new da= ";
	cin >> a; 
	s.dahike(9);
	s.calc_salary();
	s.display();
	return 0;
}

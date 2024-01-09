#include <iostream>
using namespace std;

class Salary{
	double basic;
	public:
		double gross;
		static double da;
		const double bonus;
		Salary(double , const double );
		static void dahike(double );
		void calc_salary();
		void display();	
		friend double avg(const Salary& , const Salary& );
};

Salary:: Salary(double a, const double b): bonus(b){
	gross=a;
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

double avg(const Salary &s, const Salary &t){
	if(s.gross>t.gross){
		cout << "The 1st employee has more salary" << endl;
	}
	else if(s.gross<t.gross){
		cout << "The 2nd employee has more salary" << endl;
	}
	else{
		cout << "Both have of equal salary" << endl;
	}
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
	cout << "Give the basic pay of 2nd Employee= ";
	cin >> a;
	cout << "Give the bonus for the 2nd Employee= ";
	cin >> b;
	Salary s2(a, b);
	s2.calc_salary();
	s2.display();
	avg(s, s2);
	return 0;
}

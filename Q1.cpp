#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

class Salary{
    private:
	    double basic;

	public:
		double gross;
		static double da;
		double bonus;
		Salary(double, double);
		void dahike(double);
		void calc_salary();
		void display();	
		friend void avg(const Salary&, const Salary&);
};

double Salary::da = 7;

Salary:: Salary(double s1, double s2): bonus(s2){
	gross = s1;
	basic = s1;
}

void Salary:: calc_salary(){
	double da_pay = (basic*da)/100;
	gross = bonus + basic + da_pay;
}

void Salary::display(){
	cout << "The total salary of the employee is: " << gross << endl;
}

void Salary::dahike(double da_pay){
	Salary::da = da_pay;
}

void avg(const Salary &s, const Salary &t){
	double average = (s.gross + t.gross) / 2;
    cout << "The average of the salaries is: " << average << endl; 
}

int main(){
	double a, b, hike;
    cout << "-- Employee 1 --" << endl;
	cout << "Enter the basic pay of Employee 1: ";
	cin >> a;
	cout << "Enter the bonus for the Employee 2: ";
	cin >> b;
	Salary s1(a, b);
	s1.calc_salary();
	s1.display();
	cout << "\nEnter the new DA: ";
	cin >> hike; 
	s1.dahike(hike);
	s1.calc_salary();
	s1.display();
    cout << "\n-- Employee 2 --" << endl;
	cout << "Enter the basic pay of Employee 2: ";
	cin >> a;
	cout << "Enter the bonus for the Employee 2: ";
	cin >> b;
	Salary s2(a, b);
	s2.calc_salary();
	s2.display();
    cout << "\nEnter the new DA: ";
	cin >> hike; 
	s2.dahike(hike);
	s2.calc_salary();
	s2.display();
    cout << "\n-- Average --" << endl;
	avg(s1, s2);
	return 0;
}

/*
Pyramid pattern
      *
     ***
    *****
   *******
Input : n = number of lines , c = fill character
*/
// header files for input/output and manipulators
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter number of lines : ";
	cin >> n;
	char c;
	cout << "Enter the fillchar of pattern : ";
	cin >> c;
	for (int i = 1 ; i <= n ; i++)
	{
		//cout << setw(n-i+1) << setfill(' ') << ' '<< setw(2*i) << setfill(c) << ' '<< endl ;
		cout << setw(n-i+1) << setfill(' ') << c << setw(2*i)<< setfill(c)<<' '<<endl; //<< setw(2*i) << setfill(c) << ' '<< endl ;
	}
}

/*Loop description :
	--first setw manages the leading spaces;
	--second setw manages the spaces filled by entered fillcharacter
	--after first setw,space is explicitly used to setfill because the next setfill encountered will fill any other space in the given line
	--setw and setfill are formatting parameters in cout, hence a printable output is always required. Thus after setfilling with c, space is printed as output
*/


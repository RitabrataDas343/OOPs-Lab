#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int main(){  
    double start, end, step, power, i; 
    char fill;
    cout << "Enter 1 for sin(x) curve" << endl;
    cout << "Enter 2 for cos(x) curve" << endl;
    cout << "Enter 3 for exponential curve" << endl;
    cout << "Enter your CHOICE: " ;
    int choice;
    cin >> choice;
    
    switch (choice){
        case 1:
            cout << "Enter the initial value of theta (in radians): " ; 
            cin >> start;
            cout << "Enter the final value of theta (in radians): " ; 
            cin >> end;
            cout << "Enter the step number: " ; 
            cin >> step;
            cout << "Enter the fill character: " ; 
            cin >> fill;
            for(i = start; i <= end; i += step){
                int x = floor(sin(i * 3.14 / 180) * 50);
                if(x >= 0){
                   cout <<setw(55) << setfill(' ') << "|" << setw(x) << setfill(fill) << '*' << endl;
                } else {
                       x = abs(x);
                       cout <<setw(55-x) << setfill(' ') << '*' << setw(x) << setfill(fill) << "|" << endl ;
                }
            }
            break;
        case 2:
            cout << "Enter the initial value of theta (in radians): " ; 
            cin >> start;
            cout << "Enter the final value of theta (in radians): " ; 
            cin >> end;
            cout << "Enter the step number: " ; 
            cin >> step;
            cout << "Enter the fill character: " ; 
            cin >> fill;
            for(i = start; i <= end; i += step){
                int x = floor(cos(i*3.14/180)*50);
                if(x >= 0){
                    cout <<setw(55) << setfill(' ') << "|" << setw(x) << setfill(fill) << '*' << endl;
                } else {
                    x = abs(x);
                    cout <<setw(55-x) << setfill(' ') << '*' << setw(x) << setfill(fill) << "|" << endl ;
                }
            }
            break;
        case 3:
            cout << "Enter the power: " ; 
            cin >> power;
            cout << "Enter the step number: " ; 
            cin >> step;
            cout << "Enter the fill character: " ; 
            cin >> fill;
            for(i = 0; i <= power; i += step){
                long int x = floor(exp(i));
                if(x >= 0){
                    if(x > INT64_MAX){
                        x = INT64_MAX;
                    }
                    cout << "|" << setw(x) << setfill(fill) << '*' << endl;
                } else {
                    x = abs(x);
                    cout <<setw(55-x) << setfill(' ') << '*' << setw(55-x) << setfill(fill) << "|" << endl ;
                }
            }
            break;
        default:
            cout<<"Wrong input"<<endl;
            break;
    }
    return 0;
}

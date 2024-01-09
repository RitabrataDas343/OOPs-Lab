#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int random1[10000]={0};
int random2[10000]={0};

void myrand(){
    long long int c = 0, m = powl(2, 31) - 1, a = powl(7, 5), range = 50, count = 2, val = 1, x;
    random1[0] = val;
    while (count <= 10000){
       x = (((a * val) + c) % m);
       val = x;
       random1[count - 1] = (x % 50) + 1;
       count++;
    }
}

int main(){
    int low = 1, high = 50, frequency = 10000, arr1[5]={0}, arr2[5]={0}, i, range;
    double result1 = 0, result2=0;
    range = high + 1 - low;
    srand(time(0));
    for (i = 0; i < frequency; i++){
        random2[i] =  low + (rand() % range);
    }
    myrand();
    for (i = 0; i < 10000; i++){
       arr1[random1[i]/10]++;
       arr2[random2[i]/10]++;
    }
    for(i = 0; i < 5; i++){
       result1 = result1 + ((double)pow((arr1[i]-2000), 2) / 2000);
    }
    for(i = 0; i < 5 ;i++){
       result2 = result2 + ((double)pow((arr2[i]-2000), 2) / 2000);
    }
    cout << "The results for Chi-Squared Test are:\n" << endl;
    cout << "Result of the Linear Congruential Method:\n" << result1 <<endl;
    cout << "Result of the myrand() function:\n" << result2 <<endl;
    return 0;
}

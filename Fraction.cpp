#include "bits/stdc++.h"
using namespace std;
class Fraction {
    private:
        int num;
        int den;
    public:

        Fraction(int n=0, int d=0){
            num = n;
            den = d;
        }
        
        Fraction operator + (Fraction const &obj){
            Fraction ans;
            ans.num = (num*obj.den) + (obj.num*den);
            ans.den = (den*obj.den);
            return ans; 
        }
        
        Fraction operator - (Fraction const &obj){
            Fraction ans;
            ans.num = (num*obj.den) - (obj.num*den);
            ans.den = (den*obj.den);
            return ans; 
        }
        
        Fraction operator * (Fraction const &obj){
            Fraction ans;
            ans.num = num*obj.num;
            ans.den = den*obj.den;
            return ans;
        }
        
        Fraction operator / (Fraction const &obj){
            Fraction ans;
            ans.num = num*obj.den;
            ans.den = den*obj.num;
            return ans;
        }
        
        void operator~ (){
            int val = min(num,den);
            for(int i=2;i<=val;i++){
                while(num%i==0 && den%i==0){
                    num=num/i;
                    den = den/i;
                }  
            }
        }

        bool operator == (Fraction const &obj){
            if(obj.num==num && obj.den==den)return true;
            return false;
        }

        int operator [] (int val){
            if(val==0)return num;
            else return den;
        } 

        void operator = (const Fraction& obj){
            num = obj.num;
            den = obj.den;
        }
        friend istream& operator >> (istream& is,Fraction &obj){
            cout<<"Enter the numerator & denominator part of the fraction : ";
            cin>>obj.num>>obj.den;
            return is;

        }
        friend ostream& operator << (ostream& os, Fraction &obj){
            os<<obj.num<<"/"<<obj.den<<endl;
            return os;
        }
};
int main(){
    Fraction c1,c2,c3;
    cout<<"Enter the 1st Fraction set \n";
    cin>>c1;
    cout<<"Enter the 2nd Fraction set \n";
    cin>>c2;
    cout<<"Fraction Set 1 :"<<c1;
    cout<<"Fraction Set 2 :"<<c2;
    c3 = c1 + c2;
    cout<<"Addition of 2 Fractions : "<<(c3);
    c3 = c1 - c2;
    if(c3[0]==0){
        cout<<"Difference of 2 Fractions : "<<0<<endl;    
    } else {
        cout<<"Difference of 2 Fractions : "<<(c3);
    }   
    c3 = c1 * c2;
    cout<<"Product of 2 Fractions : "<<(c3);
    ~c3;
    cout<<"Reduced fraction is "<<c3;
    c3 = c1/c2;
    if(c3[0]==c3[1]){
        cout<<"Division of 2 Fractions : "<<1<<endl;
    } else {
        cout<<"Division of 2 Fractions : "<<(c3);
    }

    return 0;
}
#include "bits/stdc++.h"
using namespace std;
class Complex {
    private:
        int real;
        int img;
    public:

        Complex(int r=0, int i=0){
            real = r;
            img = i;
        }
        
        Complex operator + (Complex const &obj){
            Complex ans;
            ans.real = obj.real + real;
            ans.img = obj.img + img;
            return ans;
        }
        
        Complex operator - (Complex const &obj){
            Complex ans;
            ans.real = real - obj.real;
            ans.img = img - obj.img;
            return ans; 
        }
        
        Complex operator * (Complex const &obj){
            Complex ans;
            ans.real = (real*obj.real)-(img*obj.img);
            ans.img = (real*obj.img)+(obj.real*img);
            return ans;
        }
        
        Complex operator / (Complex const &obj){
            Complex ans;
            ans.real = ((real*obj.real)-(img*obj.img))/((obj.real*obj.real)-(obj.img*obj.img));
            ans.img = ((real*obj.img)+(obj.real*img))/((obj.real*obj.real)-(obj.img*obj.img));
            return ans;
        }
        Complex operator ~ (){
            Complex ans;
            ans.real = real;
            ans.img = -img;
            return ans;
        }
        
        bool operator == (Complex const &obj){
            if(obj.real==real && obj.img==img)return true;
            return false;
        }

        int operator [] (int val){
            if(val==0)return real;
            else return img;
        } 

        void operator = (const Complex& obj){
            real = obj.real;
            img = obj.img;
        }
        friend istream& operator >> (istream& is,Complex &obj){
            cout<<"Enter the real & imaginary part of the complex no. : ";
            cin>>obj.real>>obj.img;
            return is;

        }
        friend ostream& operator << (ostream& os, Complex &obj){
            os<<obj.real<<" + "<<obj.img<<"i"<<endl;
            return os;
        }
};
int main(){
    Complex c1,c2,c3;
    cout<<"Enter the 1st Complex set \n";
    cin>>c1;
    cout<<"Enter the 2nd Complex set \n";
    cin>>c2;
    cout<<"Complex Set 1 :"<<c1;
    cout<<"Complex Set 2 :"<<c2;
    c3 = c1 + c2;
    cout<<"Addition of 2 complex Numbers : "<<(c3);
    c3 = c1 - c2;
    cout<<"Difference of 2 complex Numbers : "<<(c3);
    c3 = c1 * c2;
    cout<<"Product of 2 complex Numbers : "<<(c3);
    c3 = c1/c2;
    cout<<"Division of 2 complex Numbers : "<<(c3);
    return 0;
}
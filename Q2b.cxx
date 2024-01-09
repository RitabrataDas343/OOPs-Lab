#include<iostream>
#include "myMatrix.hxx"
typedef long long int lli;
using namespace std;
class Matrix2d{
    int row,col;
    int **ptr;
    public:
        Matrix2d(int,int);
        void alloc();
        void display();
        int** getVar();
        void dealloc();
};
Matrix2d::Matrix2d(int r,int c)
{
    row = r;    col = c;
    ptr = new int*[r];
    for(int i=0;i<r;i++){
        ptr[i] = new int[c];
    }
}
void Matrix2d::alloc(){
    srand(time(0));
    for(int i=0;i<row;i++){
        for(int k=0;k<col;k++){
            ptr[i][k] = rand()%10;
        }
    }
}
void Matrix2d::display(){
    for(int i=0;i<row;i++){
        for(int k=0;k<col;k++){
            cout<<ptr[i][k]<<" ";
        }
        cout<<endl;
    }
}
int** Matrix2d::getVar(){
    return ptr;
}
void Matrix2d::dealloc(){
    delete *ptr;
}
int main()
{
    cout<<"\nEnter the rows & columns of M1 : ";
    int row,col;    cin>>row>>col;
    Matrix2d m2d(row,col);
    cout<<"\nEnter the rows & columns of M2 : ";
    int row1,col1;    cin>>row1>>col1;
    Matrix2d m2d1(row1,col1);
    m2d.alloc();
    cout<<"Matrix 1 : "<<endl;
    m2d.display();
    m2d1.alloc();
    cout<<"Matrix 2 : "<<endl;
    m2d1.display();
    if(row==col1){
        cout<<"Matrix Multiplication Value : "<<endl;
        matrixMult(m2d.getVar(),m2d1.getVar(),row,col,row1);
    } else {
        cout<<"Matrix Error"<<"\n";
    }
    cout<<"The determinant value of M1 is : "<<det(row,m2d.getVar())<<endl;
    cout<<"The determinant value of M2 is : "<<det(row1,m2d1.getVar())<<endl;
    m2d.dealloc();
    return 0;
}
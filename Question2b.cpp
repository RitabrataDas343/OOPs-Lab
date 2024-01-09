#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include "myMatrix.hpp"

using namespace std;

class Matrix{
    int row;
    int col;
    int **ptr;
    public:
        Matrix(int,int);
        void allocate();
        void display();
        int** getPointer();
        void deallocate();
};

Matrix::Matrix(int r, int c){
    row= r;    
    col = c;
    ptr = new int*[r];
    for(int i = 0; i < r; i++){
        ptr[i] = new int[c];
    }
}

void Matrix::allocate(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "Enter the element: ";  
            cin >> ptr[i][j];
        }
    }
}
void Matrix::display(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<< ptr[i][j] << " ";
        }
        cout << endl;
    }
}
int** Matrix::getPointer(){
    return ptr;
}

void Matrix::deallocate(){
    delete *ptr;
}

int main(){
    int row1, col1, row2, col2;
    cout << "Enter the number of ROWS in Matrix 1: ";   
    cin >> row1;
    cout << "Enter the number of COLUMNS in Matrix 1: "; 
    cin >> col1;
    Matrix matrix1(row1, col1);
    cout << "Enter the elements of Matrix 1: " << endl;
    matrix1.allocate();
    cout << "Enter the number of ROWS in Matrix 2: ";   
    cin >> row2;
    cout << "Enter the number of COLUMNS in Matrix 2: "; 
    cin >> col2;
    Matrix matrix2(row2, col2);
    cout << "Enter the elements of Matrix 2: " << endl;
    matrix2.allocate();
    cout << "\nThe elements of Matrix 1 are: " << endl;
    matrix1.display();
    cout << "\nThe elements of Matrix 2 are: " << endl;
    matrix2.display();
    cout << "\nThe determinant of Matrix1 is : "<< getDeterminant(row1,matrix1.getPointer())<<endl;
    cout << "The determinant of Matrix2 is : "<< getDeterminant(row2,matrix2.getPointer())<<endl;
    if(row1 == col2){
        cout << "\nThe final matrix is: " << endl;
        matrixMultiplication(matrix1.getPointer(), matrix2.getPointer(), row1, col1, row2);
    } else {
        cout << "\nMultiplication not Possible." << "\n";
    }
    matrix1.deallocate();
    matrix2.deallocate();
    return 0;
}
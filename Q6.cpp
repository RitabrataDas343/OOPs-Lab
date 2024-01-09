#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

template <class T>
class matrix{
public:
    T **ptr;
    int row, col;
    matrix(int r, int c){
        row = r;
        col = c;
        ptr = new T *[row];
        for (int i = 0; i < row; i++){
            ptr[i] = new T[col];
        }
    }

    matrix<T> operator+(matrix<T> &obj){
        matrix<T> obj2(obj.row, obj.col);
        for (int i = 0; i < obj.row; i++){
            for (int j = 0; j < obj.col; j++){
                obj2.ptr[i][j] = obj.ptr[i][j] + ptr[i][j];
            }
        }
        return obj2;
    }

    matrix<T> operator*(matrix<T> &obj){
        matrix<T> obj2(row, obj.col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < obj.col; j++){
                for (int k = 0; k < obj.row; k++){
                    obj2.ptr[i][j] += (ptr[i][k] * obj.ptr[k][j]);
                }
            }
        }
        return obj2;
    }

    matrix<T> operator~(){
        matrix<T> obj2(row, col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                obj2.ptr[i][j] = ptr[j][i];
            }
        }
        return obj2;
    }

    bool operator==(matrix<T> &obj){
        if (row != obj.row || col != obj.col){
            return false;
        } else {
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    if (obj.ptr[i][j] != ptr[i][j]){
                        return false;
                    }   
                }
            }
        }
        return true;
    }

    friend istream &operator>>(istream &is, matrix<T> &obj){
        cout << "\nEnter the matrix elements : ";
        for (int i = 0; i < obj.row; i++){
            for (int j = 0; j < obj.col; j++){
                is >> obj.ptr[i][j];
            }
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, matrix<T> &obj){
        cout << "\nThe Matrix is " << endl;
        for (int i = 0; i < obj.row; i++){
            for (int j = 0; j < obj.col; j++){
                os << obj.ptr[i][j] << " ";
            }
            cout << endl;
        }
        return os;
    }

    ~matrix(){};
};

int main(void){
    cout << "--MATRIX 1--" << endl;
    matrix<int> matrix1(3, 3);
    cin >> matrix1;
    cout << matrix1;
    cout << "\n--MATRIX 2--" << endl;
    matrix<int> matrix2(3, 3);
    cin >> matrix2;
    cout << matrix2;
    cout << "\n--ADDITION OF MATRICES--" << endl;
    matrix<int> matrix3(3,3);
    matrix3 = matrix1 + matrix2;
    cout << matrix3;
    cout << "\n--MULTIPLICATION OF MATRICES--" << endl;
    matrix3 = matrix1 * matrix2;
    cout << matrix3;
    cout << "\n--TRANSPOSITION OF MATRIX 1--" << endl;
    matrix3 = ~matrix1;
    cout << matrix3;
    cout << "\n--TRANSPOSITION OF MATRIX 2--" << endl;
    matrix3 = ~matrix2;
    cout << matrix3;
    cout << "\n--TRANSPOSITION OF MATRIX 1--" << endl;
    matrix3 = ~matrix1;
    cout << matrix3;
    cout << "\n--CHECK EQUALITY OF MATRICES--" << endl;
    if(matrix1 == matrix2){
        cout << "BOTH MATRICES ARE EQUAL." << endl;
    } else {
        cout << "THE MATRICES ARE NOT EQUAL." << endl;
    }
    return 0;
}
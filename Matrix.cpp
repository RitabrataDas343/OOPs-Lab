#include "bits/stdc++.h"
using namespace std;
template <class T>
class matrix
{
public:
    T **ptr;
    int row, col;
    matrix(int r, int c)
    {
        row = r;
        col = c;
        ptr = new T *[row];
        for (int i = 0; i < row; i++)
        {
            ptr[i] = new T[col];
        }
    }
    matrix<T> operator+(matrix<T> &obj)
    {
        matrix<T> obj2(obj.row, obj.col);
        for (int i = 0; i < obj.row; i++)
        {
            for (int j = 0; j < obj.col; j++)
            {
                obj2.ptr[i][j] = obj.ptr[i][j] + ptr[i][j];
            }
        }
        return obj2;
    }
    matrix<T> operator*(matrix<T> &obj)
    {
        matrix<T> obj2(row, obj.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < obj.col; j++)
            {
                for (int k = 0; k < obj.row; k++)
                {
                    obj2.ptr[i][j] += (ptr[i][k] * obj.ptr[k][j]);
                }
            }
        }
        return obj2;
    }

    matrix<T> operator~()
    {
        matrix<T> obj2(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                obj2.ptr[i][j] = ptr[j][i];
            }
        }
        return obj2;
    }
    bool operator==(matrix<T> &obj)
    {
        if (row != obj.row || col != obj.col)
            return false;
        else
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (obj.ptr[i][j] != ptr[i][j])
                        return false;
                }
            }
        }
        return true;
    }
    friend istream &operator>>(istream &is, matrix<T> &obj)
    {
        cout << "\nEnter the matrix elements : ";
        for (int i = 0; i < obj.row; i++)
        {
            for (int j = 0; j < obj.col; j++)
            {
                is >> obj.ptr[i][j];
            }
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, matrix<T> &obj)
    {
        cout << "\nThe Matrix is " << endl;
        for (int i = 0; i < obj.row; i++)
        {
            for (int j = 0; j < obj.col; j++)
            {
                os << obj.ptr[i][j] << " ";
            }
            cout << endl;
        }
        return os;
    }
    ~matrix(){};
};
int main(void)
{
    matrix<int> mx(3, 1);
    cin >> mx;
    cout << mx;
    matrix<int> mx2(3, 3);
    cin >> mx2;
    cout << mx2;
    matrix<int> mx3(3,3);
    mx3 = mx * mx2;
    cout << mx3;
    // Fill more operations here
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long int matrixMultiplication(int **matrix1, int **matrix2, int row1, int col1, int row2){
    int arr[row1][col1]; 
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            arr[i][j] = 0;
            for (int k = 0; k < row2; k++) {
                arr[i][j] += matrix1[i][k] * matrix2[k][j];
            } 
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int getDeterminant(int row, int **arr){
    if(row == 2){
        int determinant = ((arr[0][0])*(arr[1][1])-(arr[0][1])*(arr[1][0]));
        return determinant;
    }
    else{
        int det = 0;
        for(int k = 0; k < row; k++){
            int row = 0, col = 0;
            int **arr1;
            arr1 = new int *[row - 1];
            for(int i = 0; i < row - 1; i++){
                arr1[i] = new int [row - 1];
            }
            for(int i = 1; i < row; i++){
                for(int j = 0; j < row; j++){
                    if(j == k){
                        continue;
                    }
                    arr1[row][col]=arr[i][j];
                    col++;
                }
                row++;
                col=0;
             }
            det = det + arr[0][k] * (int)pow(-1, k) * getDeterminant(row - 1, arr1);
            delete []arr1;
        }
        return det;
    }
}
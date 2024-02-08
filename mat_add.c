/*
Program takes two matrices and adds them
*/

#include <stdio.h>

/*
adds the values of two matrices
@param size: size of the matrices
@param matrixA[]: first matrix
@param matrixB[]: second matrix
@param out[]: matrix with the sum
*/
void addMatrix(int size, int matrixA[], int matrixB[], int out[]) {

    for(int i = 0; i< size; i++) {
        out[i] = matrixA[i] + matrixB[i];

    };

}

/*
gets user input on matrix
@param mat[]: matrix to hold values
@param size: size of matrix
@param prompt: prompt to user
*/
void getMatrix(int mat[], int size, const char* prompt) {
    
    printf("%s", prompt);
    for(int i = 0; i< size; i++) {
        scanf("%d", &mat[i]);
    }

}

/*
prints out matrix
@param int matrix[]: matrix to output
@param row: number of rows
@param col: number of columns
*/
void printMatrix(int matrix[], int row, int col) {
    
    for(int i = 0; i< (row*col); i++) {
        printf("%d ", matrix[i]);
        if(((i+1) % col) == 0){
            printf("\n");
        }
    }
}

int main() {
    int rows;
    int columns;

    printf("Please enter the number of rows: ");
    scanf("%d", &rows);
    printf("Please enter the number of columns: ");
    scanf("%d", &columns);
    int matA[rows * columns];
    int matB[rows * columns];
    int matSum[rows * columns];

    getMatrix(matA, rows * columns, "Enter Matrix A\n");
    getMatrix(matB, rows * columns, "Enter Matrix B\n");

    addMatrix(rows * columns, matA, matB, matSum);
    
    printf("A + B = \n");
    printMatrix(matSum, rows, columns);
    
    return 0;
}
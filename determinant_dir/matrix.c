//Program finds the determinant of a matrix

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/* reads and returns matrix of dimension dim from file pointer fp
@param fp: file pointer
@param dim: dimension of matrix
@return tempMat: matrix read from file
*/

double** get_matrix(FILE* fp, int dim) {

    double** tempMat = (double**)malloc(dim * sizeof(double*));
    for(int i = 0; i < dim; i++) {
        tempMat[i] = (double*)malloc(dim * sizeof(double));
        for(int j = 0; j < dim; j++) {
            fscanf(fp, "%lf", &tempMat[i][j]);
        }
    }
    return tempMat;
}

void print_matrix(double** matrix, int row_dim, int col_dim) {
    /*
    Print matrix to the screen
    @matrix: the matrix to be printed
    @row_dim: the number of rows in matrix
    @col_dim: the number of columns in matrix
    @returns: nothing
    @modifies: nothing
    */
    for(int i = 0; i < row_dim; i++) {
        for(int j = 0; j < col_dim; j++) {
            printf("%lf ", matrix[i][j]);

        }
        printf("\n");
    }
}

/*returns the src matrix without the first row and the column col
@param src: original matrix
@param dim: dimensions of new matrix
@param col: column  to exclude
@return tempMat: new matrix excluding first row and column col
*/
double** get_matrix_exclude(double** src, int dim, int col) {

    double** tempMat = (double**)malloc(dim * sizeof(double*));
    for(int i = 0; i < dim; i++) {
        tempMat[i] = (double*)malloc(dim * sizeof(double));
    }

    for(int j = 0; j < col; j++) {
        for(int i = 0; i < dim; i++) {
            tempMat[i][j] = src[i+1][j];
        }
    }
    for(int j = col+1; j < dim+1; j++) {
        for(int i = 0; i < dim; i++) {
            tempMat[i][j-1] = src[i+1][j];
        }
    }

    return tempMat;

}

/*returns the determinant of matrix
@param matrix: matrix to find determinant of
@param dimensions: dimensions of matrix
@return sum: the determinant

*/
double determinant(double** matrix, int dimensions) {
    if(dimensions == 1) {
        return matrix[0][0];
    }
    else {
        double sum = 0;
        for(int i = 0; i < dimensions; i++) {
            Matrix* smallMat = (Matrix*)malloc(1 * sizeof(Matrix));
            smallMat->dimensions = dimensions-1;
            smallMat->matrix = get_matrix_exclude(matrix, dimensions-1, i);
            if(i % 2 == 0) {
            sum += (matrix[0][i] * determinant(smallMat->matrix, smallMat->dimensions));
            }
            else {
            sum -= (matrix[0][i] * determinant(smallMat->matrix, smallMat->dimensions));
            }
        }
        return sum;

    }

}
#ifndef MATRIX_H
#define MATRIX_H

    typedef struct Matrix_struct{
    int dimensions;
    double** matrix;

    }Matrix;
    double** get_matrix(FILE* fp, int dim);
    void print_matrix(double** matrix, int row_dim, int col_dim);
    double** get_matrix_exclude(double** src, int dim, int col);
    double determinant(double** matrix, int dimensions);
#endif
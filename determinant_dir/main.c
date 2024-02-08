#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main(int argc, char** argv) {
    FILE* file = fopen(argv[1], "r");
    int rows;
    int cols;
    double det;
    if(file == NULL){
        printf("Couldn't open file %s\n", argv[1]);
        return -1;
    }
    fscanf(file, "%d", &rows);
    fscanf(file, "%d", &cols);

    Matrix* matPoint = (Matrix*)malloc(1 * sizeof(Matrix));
    matPoint->dimensions = rows;
    matPoint->matrix = get_matrix(file, rows);

    det = determinant(matPoint->matrix, matPoint->dimensions);
    printf("The determinant is %.2lf.", det);

    return 0;

}
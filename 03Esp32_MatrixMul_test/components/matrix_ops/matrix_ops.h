#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3

// Function prototypes
void generate_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
void multiply_matrices(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]);
void print_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

#endif // MATRIX_OPS_H
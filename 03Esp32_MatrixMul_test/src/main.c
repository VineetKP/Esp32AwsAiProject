#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "matrix_ops.h"  // Include the custom matrix operations component

void app_main(void) {
    printf("Hello from ESP32!\n");

    // Seed the random number generator
    srand(time(NULL));

    int matrix1[MATRIX_SIZE][MATRIX_SIZE];
    int matrix2[MATRIX_SIZE][MATRIX_SIZE];
    int result[MATRIX_SIZE][MATRIX_SIZE];

    // Generate random matrices
    generate_matrix(matrix1);
    generate_matrix(matrix2);

    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);

    // Multiply matrices
    multiply_matrices(matrix1, matrix2, result);

    printf("Resultant Matrix:\n");
    print_matrix(result);

    printf("Matrix Multiplication Complete!\n");

    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Prevent the task from exiting
    }
}
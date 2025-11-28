#include <stdio.h>

#define ROWS 4
#define COLS 4

void bubble_sort(int row[]) {
    for (int i = 0; i < COLS - 1; i++) {
        for (int j = 0; j < COLS - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                int temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {4, 2, 1, 3},
        {8, 6, 5, 7},
        {12, 10, 9, 11},
        {16, 14, 13, 15}
    };
    
    printf("Исходная матрица:\n");
    printMatrix(matrix);
    
    for (int i = 0; i < ROWS; i++) {
        bubble_sort(matrix[i]);
    }
    
    printf("\nПосле сортировки строк:\n");
    printMatrix(matrix);
    
    int hasZero = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 0) {
                hasZero = 1;
                break;
            }
        }
        if (hasZero) break;
    }
    printf(hasZero ? "\nЕсть нули\n" : "\nНет нулей\n");
    
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Среднее: %.2f\n", (double)sum / (ROWS * COLS));
    
    for (int i = 0; i < ROWS; i++) {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][COLS - 1 - i];
        matrix[i][COLS - 1 - i] = temp;
    }
    
    printf("\nПосле обмена диагоналей:\n");
    printMatrix(matrix);
    
    return 0;
}

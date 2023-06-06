#include <stdio.h>

#define MAX_SIZE 100 // максимальный размер матрицы

int main() {
    int m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE];
    int m1_rows, m1_cols, m2_rows, m2_cols;

    // открытие файлов с матрицами
    FILE* file_m1 = fopen("matrix1.txt", "r");
    FILE* file_m2 = fopen("matrix2.txt", "r");


    // чтение размеров первой матрицы
    fscanf(file_m1, "%d %d", &m1_rows, &m1_cols);

    // чтение элементов первой матрицы
    for (int i = 0; i < m1_rows; i++) {
        for (int j = 0; j < m1_cols; j++) {
            fscanf(file_m1, "%d", &m1[i][j]);
        }
    }

    // чтение размеров второй матрицы
    fscanf(file_m2, "%d %d", &m2_rows, &m2_cols);

    // чтение элементов второй матрицы
    for (int i = 0; i < m2_rows; i++) {
        for (int j = 0; j < m2_cols; j++) {
            fscanf(file_m2, "%d", &m2[i][j]);
        }
    }

    // проверяем возможность умножения матриц
    if (m1_cols != m2_rows) {
        printf("Ошибка: невозможно умножить матрицы\n");
        return 0;
    }

    // вычисление произведения
    for (int i = 0; i < m1_rows; i++) {
        for (int j = 0; j < m2_cols; j++) {
            int sum = 0;
            for (int k = 0; k < m1_cols; k++) {
                sum += m1[i][k] * m2[k][j];
            }
            product[i][j] = sum;
        }
    }

    // вывод результата
    printf("Матрица произведения:\n");
    for (int i = 0; i < m1_rows; i++) {
        for (int j = 0; j < m2_cols; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    // закрытие файлов
    fclose(file_m1);
    fclose(file_m2);

    return 0;
}
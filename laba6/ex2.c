#include <stdio.h>

int position(int* Arr1, int s, int num);

int main() {
    int arr2[3][3] = {{1,12,32},{4,51,2},{23,24,252}};
    int* Arr1 = arr2[0];
    int s = 3;
    int st = 3;
    int num;
    
    printf("Введите число: \n");

    for (s = 0; s < 3; s++) {
        for (st = 0; st < 3; st++) {
            printf("%d ", arr2[s][st]);
        }
    }

    printf("\n");
    scanf(" %d", &num);

    position(Arr1, s, num);

    return 0;
}

int position(int* Arr1, int s, int num) {
    
    s = 0;

    for (s = 0; s < 9; s++) {
        if (num == *(Arr1 + s)) {
            printf("Строка: %d\nСтолбец: %d", s/3 + 1, s%3 + 1);
            break;
        }
    }
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void selection(char** arr);
void bubble(char** arr);
void combSort(char** arr);
void changestr(char* x, char* y);
void word(char* arr);
void print(char** arr);
void copy(char** arr, char** copyArr);

int main() {
    int i;
    char** strArr = (char**)malloc(sizeof(char*)*10);
    char** copyArr = (char**)malloc(sizeof(char*)*10);
    for (i = 0; i < 10; i++) {strArr[i] = (char*)malloc(sizeof(char)); copyArr[i] = (char*)malloc(sizeof(char));}

    printf("Введите 10 слов: \n");
    for (i = 0; i < 10; i++) {word(strArr[i]);}
    
    printf("Введите номер операции:\n1. selection\n2. bubble\n3. CombSort\n4. Применить всё\n");
    scanf("%d", &i);

    if (i == 1) {selection(strArr);}
    else if (i == 2) {bubble(strArr);}
    else if (i == 3) {combSort(strArr);}
    else if (i == 4) {
        copy(strArr, copyArr);
        clock_t start = 0, end = 0;
        start = clock();
        selection(copyArr);
        end = clock();
        printf("Время выполнения: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        copy(strArr, copyArr);
        start = 0, end = 0;
        start = clock();
        bubble(copyArr);
        end = clock();
        printf("Время выполнения: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        start = 0, end = 0;
        start = clock();
        combSort(strArr);
        end = clock();
        printf("Время выполнения: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);
        }
    return 0;
}

void selection(char** arr) {
    printf("selection:\n");   
    int i, j, min_idx, count = 0, size = 10;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++)
        {
          if (strcmp(arr[j], arr[min_idx]) < 0)
              min_idx = j;
        }
        if (min_idx != i) {
            changestr(arr[min_idx], arr[i]);
            print(arr);
            count += 1;
        }
    }
    printf("Кол-во итераций: %d\n", count);
}

void bubble(char** arr) {
    printf("bubble:\n");
    int i, j, count = 0, size = 10;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                changestr(arr[j], arr[j + 1]);
                print(arr);
                count += 1;
            }
        }
    }
    printf("Кол-во итераций (bubble): %d\n", count);
}

void combSort(char** arr) {
    printf("CombSort:\n");
    
    int count = 0, size = 10, swapped = 1;
    float gap = (size/1.3);

    while(gap > 1 || swapped) {
        swapped = 0;
        if (gap < 1) {gap = 1;}
        int igap = (int) gap;

        for(int i = 0; i + igap < size; i++) {
            if(strcmp(arr[i], arr[i +igap]) > 0) {changestr(arr[i], arr[i + igap]); swapped = 1; print(arr); count += 1;}
        }
        gap /= 1.3;
    }
    printf("Кол-во итераций (CombSort): %d\n", count);
}

void print(char** arr) {
    printf("[");
    for (int i = 0; i < 10; i++) {
        if (i == 9) {printf("%s", arr[i]);}
        else {printf("%s, ", arr[i]);}
    }
    printf("]\n");
}

void word(char* arr) {
    char str[20];
    scanf("%s", str);
    strcpy(arr, str);
}

void copy(char** arr, char** copyArr) {
    for (int i = 0; i < 10; i++) {strcpy(copyArr[i], arr[i]);}
}

void changestr(char* x, char* y) {
	char temp[20];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}
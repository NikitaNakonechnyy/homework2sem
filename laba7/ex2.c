#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void selection(char** arr);
void bubble(char** arr);
void comb(char** arr);
void changestr(char* a, char* b);
void word(char* arr);
void print(char** arr);
void copb(char** arr, char** copbArr);


int main() {
    int i;
    char** strArr = (char**)malloc(sizeof(char*)*10);
    
    for (i = 0; i < 10; i++) {strArr[i] = (char*)malloc(sizeof(char));}

    printf("Введите 10 слов: \n");
    for (i = 0; i < 10; i++) {word(strArr[i]);}
    comb(strArr);

    return 0;
}




void comb(char** arr) {
    printf("comb:\n");
    
    int x = 0, size = 10, z = 1;
    float gap = (size/1.3);

    while(gap > 1 || z) {
        z = 0;
        if (gap < 1) {gap = 1;}
        int igap = (int) gap;

        for(int i = 0; i + igap < size; i++) {
            if(strcmp(arr[i], arr[i +igap]) > 0) {changestr(arr[i], arr[i + igap]); z = 1; print(arr); x += 1;}
        }
        gap /= 1.3;
    }
    printf("Кол-во итераций (comb): %d\n", x);
}




void print(char** arr) {
    printf("[");
    for (int i = 0; i < 10; i++) {
        if (i == 9) {printf("%s", arr[i]);}
        else {printf("%s, ", arr[i]);}
    }
    printf("]\n");
}



void changestr(char* a, char* b) {
	char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}


void word(char* arr) {
    char str[20];
    scanf("%s", str);
    strcpy(arr, str);
}


#include <stdio.h>
#include <stdlib.h>

int maxLength(char arr[], char s);

int main() {
    char arr[] = {'h','e','l','l','l','o', 'o','h','h','\n'};
    char s;

    printf("Введите символ: ");
    scanf(" %c", &s);
    printf("%d", maxLength(arr, s));
    return 0;
}

int maxLength(char arr[], char s) {

    int am_of_symb = 0;
    int max_am_of_symb = 0;
    int i = 0;
    int arrLength = 8;
    char* ptrArr;

    ptrArr = (char*)malloc(arrLength * sizeof(char));

    for (i = 0; i < arrLength; i++) {
		ptrArr[i] = arr[i];
	}

    i = 0;

    while  (i < arrLength) {
            if (arr[i] == s) {
                am_of_symb += 1;
                if (am_of_symb > max_am_of_symb) {
                    max_am_of_symb = am_of_symb;
                }  
            } else {
                am_of_symb = 0;
            }
            i += 1;
        }

    return max_am_of_symb;
}
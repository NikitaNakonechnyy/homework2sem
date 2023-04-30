#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char word[100];
    int i;
    int j;
    int glas =0;
    char *sym;
    char mas[6] = "aeiouy";

    printf("Введите слово: ");
    scanf("%s", &word);
    sym = word;

    for (i = 0; i < 10 ; i++) {
        for (j = 0; j < 6; j++){
            if (*(sym + i) == mas[j]) {
                glas++;
            }
        }
    }

    printf("%d Гласных в данном слове\n%d Согласных в данном слове", glas, strlen(word)-glas);
    
    return 0;
}
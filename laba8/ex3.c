
#include <stdio.h>
#include <locale.h>



int main() { 
    setlocale(LC_ALL, "Rus");
    char ch;
    int des_value;
    FILE *file;
    char file_name[100];

    printf("Введите имя файла или 'keyboard' для ввода с клавиатуры: ");
    scanf("%s", file_name);

    if(strcmp(file_name, "keyboard") == 0) {
        printf("Введите сообщение");
        while((ch = getchar()) != EOF) {
            des_value = ch;
            if(des_value == 32) {
                printf("Пробел: %d\n", des_value);
            } else if(des_value < 32 || des_value == 127) {
                printf("Непечатаемый символ: %d\n", des_value);
                if(des_value == 9) {
                    printf("\\t");
                } else if(des_value == 10) {
                    printf("\\n");
                }
            } else {
                printf("%c: %d\n", ch, des_value);
            }
        }
    } else {
        file = fopen(file_name, "r");
        while((ch = fgetc(file)) != EOF) {
            des_value = ch;
            if(des_value == 32) {
                printf("Пробел: %d\n", des_value);
            } else if(des_value < 32 || des_value == 127) {
                printf("Непечатаемый символ: %d\n", des_value);
                if(des_value == 9) {
                    printf("\\t");
                } else if(des_value == 10) {
                    printf("\\n");
                }
            } else {
                printf("%c: %d\n", ch, des_value);
            }
        }
        fclose(file);
    }

    return 0;
}
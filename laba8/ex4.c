
#include <stdio.h>

int main() {
    FILE *file1, *file2;
    char filename[100];

    printf("Введите имя копируемого файла: ");
    scanf("%s", filename);
    
    // открытие файла
    file1 = fopen(filename, "rb");

    // открытие файла2
    file2 = fopen("copied.txt", "wb");
    
    long int filesize;
    // определение размера файла
    fseek(file1, 0, SEEK_END); // перемещение курсора в конец файла
    filesize = ftell(file1); // определение позиции курсора - равно размеру файла
    fseek(file1, 0, SEEK_SET); // перемещение курсора в начало файла

    char buffer[1024];
    int n;
    // чтение и запись блоками по 1 кб
    while (filesize > 0) { 
        n = fread(buffer, 1, 1024, file1);
        fwrite(buffer, 1, n, file2);
        filesize -= n;
    }

    printf("Файл скопированн");
    fclose(file1);
    fclose(file2);
    return 0;
}

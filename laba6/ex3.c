//1 вариант - статический  массив

#include <stdio.h>

int maxsize;
int am_elem;





int main(){

    int ar_s;
    int numArr[maxsize];
    int maxx;
    int i;


    for (i = 0; i < maxx; i++){
    printf("Введите максимальный размер массива: ");

    scanf("%d", &maxsize);
    {
    //maxsize == 5;
    
    printf("Введите количество элементов: ");
    scanf("%d", &am_elem);
    //am_elem == 5;


    if (maxsize < am_elem) {
        printf("Количество элементов превышает размер массива ");


    }

    for (ar_s = 0; ar_s < maxsize; ar_s++) {
        if (ar_s < am_elem) {
            numArr[ar_s] = 0;
        }
    }   


    int num;
    int choice;

        
    printf("Введите число, которое вы хотите добавить в массив: ");
    scanf("%d", &num);
        
    printf("Введите номер операции, которую вы хотите произвести: 1 - вставить элемент в середину массива 2 - вставить элемент в //конец массива: ");
    scanf("%d", &choice);
    if (choice == 1) {
        insert(numArr, maxsize, num);
    } else if (choice == 2) {
        append(numArr, maxsize, num);
    }

    return 0;
    }
}
}





void print(int numArr[], int maxsize) {
    int j;

    printf("{");
    for (j = 0; j < maxsize; j++) {
        if (j == maxsize) {
            printf("%d}\n", numArr[j]);
            break;
        }
        printf("%d, ", numArr[j]);
    }




}

void insert(int numArr[], int maxsize, int num) {
    numArr[maxsize/2] = num;
    print(numArr, maxsize);
}





    
void append(int numArr[], int maxsize, int num) {
    numArr[maxsize - 1] = num;
    print(numArr, maxsize);
}
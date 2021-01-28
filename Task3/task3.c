#include <stdio.h>

/*Напишете функция, която получава като параметър две числа, и връща като резултат броя на позициите в битовото представяне на числата, на които двете числа имат различни стойности. Водещите нули да се игнорират (тоест броенето да започне от най-старшия вдигнат бит на по-голямото число).
Пример:
Вход: 15 8
Изход: 3
Обяснение: 15 -> 1111, 8 -> 1000, двете числа имат различни битове на позиции 1, 2 и 3. */

unsigned int findDif(unsigned int a, unsigned int b);
void decToBin(unsigned int n);

int main(void){

    int a, b;

    printf("\nEnter decimal value for A: ");
    scanf("%d", &a);

    if (a < 0){
        a = ~a;
        a += 1;
    }
    printf("You entered A with absolute value of %d\n", a);
    decToBin(a);


    printf("\n\nEnter decimal value for B: ");
    scanf("%d", &b);

    if (b < 0){
        b = ~b;
        b += 1;
    }
    printf("You entered B with absolute value of %d\n", b);
    decToBin(b);


    printf("\n\nThe sum of the differences between the numbers on bit level is: %d\n\n", findDif(a, b));

    return 0;
}

unsigned int findDif(unsigned int a,unsigned int b){
    unsigned int res = a ^ b;
    unsigned int counter = 0;
    unsigned char cCheck = 1;

    do{
        counter += res & cCheck;
    }while(res>>=1);

    return counter;
}

void decToBin(unsigned int n){

    printf("Binary value is: ");

    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    printf("\n");
}
/* Напишете функция, която получавa  като параметър две числа, и връща като резултат броя на позициите в битовото представяне на числата, на които двете числа имат различни стойности. Водещите нули да се игнорират (тоест броенето да започне от най-старшия вдигнат бит на по-голямото число). */
#include <stdio.h>

unsigned int findDif(unsigned int a, unsigned int b);
void decToBin(unsigned int n);
int inputDigit(char letter);

int main(void){

    int a = inputDigit('A');
    int b = inputDigit('B');
    
    printf("\n\nThe sum of the differences between the numbers on bit level is: %d\n\n", findDif(a, b));
    return 0;
}

int inputDigit(char letter){
    int status, number;

    do{
        printf("Enter a decimal value for %c: ", letter);
        status = scanf("%d", &number);
        getchar();
        if (status == 0){
            printf("Invalid decimal. Pls. enter again.\n");
        }     
    } while (status == 0);

    if (number < 0){
       	number = ~number;
       	number += 1;
    }
    printf("You entered %c with absolute value of %d\n", letter, number);
    printf("Binary value is: ");
    decToBin(number);
   
    return number;
}

unsigned int findDif(unsigned int a, unsigned int b){
    unsigned int res = a ^ b;
    unsigned int counter = 0;
    unsigned char cCheck = 1;

    do{
        counter += res & cCheck;
    }while(res>>=1);

    return counter;
}
void decToBin(unsigned int n){
    unsigned i;
    unsigned iCheck = 31;
    for (i = 1 << iCheck; i > 0; i = i >> 1){
        (n & i) ? printf("1") : printf("0");
    }
    printf("\n");
}
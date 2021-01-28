/* Напишете функция, която получавa  като параметър две числа, и връща като резултат броя на позициите в битовото представяне на числата, на които двете числа имат различни стойности. Водещите нули да се игнорират (тоест броенето да започне от най-старшия вдигнат бит на по-голямото число). */
#include <stdio.h>

int numberDigits(unsigned int a, unsigned int b);
void decToBin(unsigned int n);
int inputDigit(char number);

int main(void){

    int a = inputDigit('A');
    int b = inputDigit('B');
    
    printf("\n\nThe sum of the differences between the numbers on bit level is: %d\n\n", numberDigits(a, b));
    return 0;
}

int inputDigit(char number){
    int status, a;

    do{
        printf("Enter a decimal value for %c: ", number);
        status = scanf("%d", &a);
        getchar();
        if (status == 0){
            printf("Invalid decimal. Pls. enter again.\n");
        }     
    } while (status == 0);

    if (a < 0){
       	a = ~a;
       	a += 1;
    }
    printf("You entered %c with absolute value of %d\n", number, a);
    printf("Binary value is: ");
    decToBin(a);
   
    return a;
}

int numberDigits(unsigned int a, unsigned int b){
    int c = a ^ b;
	int n = 0;
	while(c != 0){
		if(c & 1)
			++ n;
		c >>= 1;
   	}
    return n;
}
void decToBin(unsigned int n){
    unsigned i;
    unsigned iCheck = 31;
    for (i = 1 << iCheck; i > 0; i = i >> 1){
        (n & i) ? printf("1") : printf("0");
    }
    printf("\n");
}
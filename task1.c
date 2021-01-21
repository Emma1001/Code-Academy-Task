#include <stdio.h>

int main() {
    float height;
    do {
        printf("Enter your height: ");
        scanf("%f", &height);
    } while (height <= 0);
    
    return 0;
}
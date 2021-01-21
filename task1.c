#include <stdio.h>

int main() {
    float height;
    do {
        printf("Enter your height: ");
        scanf("%f", &height);
    } while (height <= 0);

    if (height <= 145) {
        printf("Small height\n");
    }
    else if(height >= 146 && height <= 180) {
        printf("Average height\n");
    }
    else if(height >= 181 && height <= 205) {
        printf("High height\n");
    }
    else {
        printf("Extremely high height\n");
    }

    return 0;
}
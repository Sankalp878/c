#include <stdio.h>

int main() {
    int num;
    printf("Enter an odd number: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("Please enter an odd number only.\n");
        return 1; // exit the program
    }

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            if (i == (num / 2) + 1 || j == (num / 2) + 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}


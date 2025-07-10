#include <stdio.h>

int main() {
    int row,column;
    printf("Enter an odd number: ");
    scanf("%d %d", &row,&column);


    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) {
            if (i ==1 || i == row || j==1 || j==column)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}


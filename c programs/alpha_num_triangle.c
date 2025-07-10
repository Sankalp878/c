#include <stdio.h>

int main()
{

    int rows;
    printf("enter");
    scanf("%d", &rows);
    for (int i = 1; i <= rows; i++){
        int alphabet = 65;
        if (i % 2 == 0){
            for (int j = 1; j <= i; j++) {
                printf("%d",j);
            }
            printf("\n");
        }
        else{
            for (int j = 0; j < i; j++){
                printf("%c",alphabet);
                alphabet++;
            }
            printf("\n");
        }
    }
}
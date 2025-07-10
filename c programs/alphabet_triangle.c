#include<stdio.h>

int main()
{
    int row;
    printf("enter rows and columns:");

    scanf("%d", &row);
     
    for (int i = 1; i <= row; i++)    {
        int alphabet=65;
        for (int j = 0; j < i; j++)
        {
            printf("%c",alphabet);
            alphabet=alphabet+1;
        }
        printf("\n");
    }
}
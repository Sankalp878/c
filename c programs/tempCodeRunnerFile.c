include <stdio.h>

int main()
{
    int row;
    printf("enter rows and columns:");

    scanf("%d", &row);
     
    for (int i = 1; i <= row; i++)    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
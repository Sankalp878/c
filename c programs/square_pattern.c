#include <stdio.h>

int main()
{
    int row, column;
    printf("enter rows and columns:");
    scanf("%d", &row);
    scanf("%d", &column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}
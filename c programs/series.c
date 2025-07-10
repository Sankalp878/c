#include <stdio.h>

int main()
{
    int num, sum = 0;
    printf("number");
    scanf("%d", &num);
    for (int i = 1; i <=num; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + i;
        }
        else
        {
            sum = sum - i;
        }
    }
    printf("%d", sum);
}
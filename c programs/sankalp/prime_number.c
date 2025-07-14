#include <stdio.h>
int main()
{
    int num;
    printf("enter number : ");
    scanf("%d", &num);
    int flage;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            flage = 0;
            break;
        }
        else
        {
            flage = 1;
        }
    }
    if (flage == 0)
    {
        printf("your entered number is not prime");
    }
    else
    {
        printf("your enterd number is prime");
    }
}
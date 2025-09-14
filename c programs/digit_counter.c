#include <stdio.h>

int main()
{
    int quotent, i = 0;
    printf("enter any number");
    scanf("%d", &quotent);
    while (quotent != 0)
    {
        quotent = quotent / 10;
        i = i + 1;
    }
    printf("there are %d digits in given number :", i);
}

#include <stdio.h>

int main()
{
    int s1, s2, s3;
    printf("enter length of   side of triangel :");
    scanf("%d", &s1);
    printf("enter length of   side of triangel :");
    scanf("%d", &s2);
    printf("enter length of   side of triangel :");
    scanf("%d", &s3);
    if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)
    {
        printf("given sides form triangel");
    }
    else
    {
        printf("given sides does not form triangle");
    }
}
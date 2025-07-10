#include<stdio.h>
int main(){
    int divident,divisor,remainder;
    printf("enter divident:");
    scanf("%d",&divident);
    printf("enter divisor:");
    scanf("%d",&divisor);
    remainder=divident-(divisor*(divident/divisor));
    printf(" remainder is %d",remainder);
}
#include<stdio.h>

int main(){
    int num;
    int sum=0;
    printf("enter a number :");
    scanf("%d",&num);
    while(num!=0){
        sum=sum+(num%10);
        num=num/10;
    }
    printf("sum of digits of given number is %d",sum);
}
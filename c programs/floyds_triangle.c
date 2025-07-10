#include<stdio.h>

int main(){
    int num;
    printf("enter last number");
    scanf("%d",&num);
    int number=1;
    for(int i=0;i<num;i++){
        for(int j=0;j<=i;j++){
            printf("%d",number);
            number++;
        }
        printf("\n");
    }
}
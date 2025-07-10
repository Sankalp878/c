#include<stdio.h>

int main(){
    int num;
    printf("enter number");
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            if(i==j || j+i==(num+1)) printf("*");
            else{printf(" ");
        }}
        printf("\n");
    }
}
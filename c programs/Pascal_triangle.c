#include<stdio.h>
int factorial(int num){
    int factorial=1;
    if(num==0) return 1;
    else{
        for (int i=2;i<=num;i++){
            factorial=factorial*i;
        }
        return factorial;
    }}

int combination(int n,int r){
    if (n < r || n < 0 || r < 0) {
        printf("Invalid input: n must be >= r and both >= 0\n");
        return 1;}
    int c=factorial(n)/(factorial(r)*(factorial(n-r)));
    return c;

}


int main(){
    int rows;
    printf("enter number of rows");
    scanf("%d",&rows);
    for(int i=0;i<rows;i++){
       for (int space = 0; space < rows - i - 1; space++) {
            printf("  "); // two spaces per empty cell
        }
        for(int j=0;j<=i;j++){
            printf("%d ",combination(i,j));
        }
        printf("\n");
    }


}
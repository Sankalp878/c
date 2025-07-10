 #include<stdio.h>

 int factorial(int num){
    int factorial=1;
    if(num==0) return 1;
    else{
        for (int i=2;i<=num;i++){
            factorial=factorial*i;
        }
        return factorial;
    }
 }
 int main(){
    int n,r;
    printf("enter value of n and r:");
    scanf("%d %d",&n,&r);
    if (n < r || n < 0 || r < 0) {
        printf("Invalid input: n must be >= r and both >= 0\n");
        return 1;}
    int c=factorial(n)/(factorial(r)*(factorial(n-r)));

    printf("%d",c);
 }
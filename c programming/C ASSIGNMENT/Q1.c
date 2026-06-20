#include<stdio.h>
int main(){

    int n;

    printf("Enter a number:");
    scanf("%d",&n);

    if(n<0){
        printf("Enter a positive number\n");
    }

    else{
        if(n%2==0){
            printf("%d is a even number\n",n);

        }
        else{
            printf("%d is an odd number",n);
        }
    }
}
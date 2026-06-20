#include<stdio.h>



int main(){
    int n;
    long fact=1;

    printf("Enter a number:");
    scanf("%d",&n);

    for(int i=n;i>0;i--){
        fact*=i;
    }

    if(n<0){
        printf("enter a positive number\n");
    }

    else if(n==0){
        fact=1;
        printf("The factorial of the given number is %ld",fact);
    }

    else{
        printf("The factorial of the given number is %ld",fact);

    }
    
    

    return 0;
}
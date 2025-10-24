#include<stdio.h>
int main(){

    int a;

    printf("enter a number:");
    scanf("%d",&a);

    

    if(a%2==0&&a%5==0){
        printf("the number is even and divible by 5\n");

    }
    else if(a%2==0&&a%5!=0){
        printf("the number is even and but not divisible by 5\n");

    }
    else if(a%2!=0&&a%5==0){
        printf("the number is not even but divisible by 5\n");
    }
    else{
        printf("the number is not even and not divisible by 5\n");
    }


    
    
    return 0;
}
//to check whether number is even or odd

#include<stdio.h>
int main(){

    int a;

    printf("enter the number:");
    scanf("%d",&a);

    

    a%2==0?printf("the number is even"):printf("the number is odd");
    return 0;
    
}
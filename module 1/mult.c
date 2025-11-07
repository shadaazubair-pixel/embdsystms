#include<stdio.h>
int main(){
    int num1,num2,result=0;
    printf("enter the numbers:");
    scanf("%d %d",&num1,&num2);

    for(int i=1;i<=num2;i++){
        result+=num1;

    }
    printf("the product of the numbers is %d",result);
    return 0;
}
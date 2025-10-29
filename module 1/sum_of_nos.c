#include<stdio.h>
int main(){
    int num,sum=0,rem;
    printf("enter the number:");
    scanf("%d",&num);

   /* while(num>0){
        rem=num%10;
        sum+=rem;
        num=num/10;

    }
    printf("the sum of the digits= %d",sum);*/

    do{
        rem=num%10;
        sum+=rem;
        num=num/10;

    }while(num=0);

    printf("the sum of digits is %d",sum);
    return 0;
}
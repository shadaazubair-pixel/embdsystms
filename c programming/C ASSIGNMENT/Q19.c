#include<stdio.h>
int main(){
    int num1,num2,pos,n,mask=0;

    printf("enter two numbers:");
    scanf("%d %d",&num1,&num2);

    printf("enter the bit position:");
    scanf("%d",&pos);

    printf("enter the number of bit:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        num1&=~(1<<pos+i);
        mask|=(1<<pos+i);
        

        
    }

    num2&=mask;
    num1|=num2;


    printf("the number is %d",num1);







    return 0;
}
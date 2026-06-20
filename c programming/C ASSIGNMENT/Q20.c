#include <stdio.h>

int main()
{
    int num1,num2,pos,n,mask = 0,temp1,temp2;

    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);

    printf("Enter starting position: ");
    scanf("%d",&pos);

    printf("Enter number of bits to swap: ");
    scanf("%d",&n);

    
    for(int i=0;i<n;i++)
    {
        mask|=(1<<pos+i);
    }

    
    temp1=num1&mask;
    temp2=num2&mask;

    
    num1&=~mask;
    num2&=~mask;

    
    num1|=temp2;
    num2|=temp1;

    printf("After swapping:\n");
    printf("num1= %d\n",num1);
    printf("num2= %d\n",num2);

    return 0;
}
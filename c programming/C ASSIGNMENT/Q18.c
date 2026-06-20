#include<stdio.h>
int main(){

    int num,n,pos,mask=0;
    printf("enter the number:");
    scanf("%d",&num);

    printf("Enter the bit position:");
    scanf("%d",&pos);

    printf("enter no:of bits to be toggled:");
    scanf("%d",&n);


    num>>=pos;


    for(int i=0;i<n;i++){
        mask|=(1<<i);
        

        

        

    }

    num&=mask;


    printf("the number is %d",num);



    return 0;
}
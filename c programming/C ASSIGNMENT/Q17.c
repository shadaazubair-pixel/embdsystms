#include<stdio.h>
int main(){

    int num,n,pos;
    printf("enter the number:");
    scanf("%d",&num);

    printf("Enter the bit position:");
    scanf("%d",&pos);

    printf("enter no:of bits:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        num^=(1<<pos+i);
        

    }


    printf("the number is %d",num);



    return 0;
}
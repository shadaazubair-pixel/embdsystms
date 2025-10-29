#include<stdio.h>
int main(){
    int num,rem,product=1;
    printf("enter the number:");
    scanf("%d",&num);

    if(num==0){
        printf("the product is 0\n");
    }
    else{

    

    while(num>0){
        rem=num%10;
        product*=rem;
        num=num/10;

    }

    

    
    printf("the product of digits=%d",product);}
    
    return 0;
}
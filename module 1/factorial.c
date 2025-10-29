#include<stdio.h>
int main(){
    int n;
    long long fact=1;  //factorial grows rapidly so use larger data type
    

    printf("enter the number:");
    scanf("%d",&n);
    
    if(n<=0){
        printf("the factorial cannot be calculated\n");

    }
    else{

    

    while(n>1){
        fact=fact*n;
        n--;
    }
    printf("the factorial of the number is %lld\n",fact);
}
printf("size of long %d",sizeof(long long));

    return 0;
}
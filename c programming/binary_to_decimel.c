#include<stdio.h>
int main(){
    int bin,rem,dec=0,j=1,d,n;

    printf("Enter the binary number:");
    scanf("%d",&bin);
    n=bin;
    

    while(n>0){
        rem=n%10;
        d=rem*j;
        dec+=d;
        j*=2;
        n/=10;

    }
    printf("the binary form is %d and the decimel form is %d",bin,dec);
    return 0;
}

//to find smallest of three numbers using ternary operator

#include<stdio.h>
int main(){

    int a,b,c,smallest;

    printf("a=");
    scanf("%d",&a);

    printf("b=");
    scanf("%d",&b);

    printf("c=");
    scanf("%d",&c);

    smallest=a<b?((a<c)?a:c):((b<c)?b:c);
    printf("the smallest number is %d\n",smallest);
    return 0;
}
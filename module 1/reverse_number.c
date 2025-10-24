#include<stdio.h>

int main(){

    int num,a,b,c,rev_num;

    printf("enter the first digit:");
    scanf("%d",&a);

    printf("enter the second digit:");
    scanf("%d",&b);

    num=(a*10)+(b*1);
    printf("the number is %d\n",num);

    rev_num=(b*10)+(a*1);
    printf("the reverse of the number is %d\n",rev_num);

    return 0;
}
#include<stdio.h>
int main(){

    int divident, divisor, reminder, quotient;

    printf("enter the divident");
    scanf("%d",&divident);

    printf("enter the divisor");
    scanf("%d",&divisor);

    quotient=divident/divisor;
    printf("the quotient is %d\n",quotient);

    reminder=divident%divisor;
    printf("the reminder is %d, reminder");

}
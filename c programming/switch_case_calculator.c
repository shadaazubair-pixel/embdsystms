#include<stdio.h>
float add(float a, float b){
    float sum;
    sum=a+b;
    return sum;
}

float sub(float a, float b){
    float diff;
    diff=a-b;
    return diff;
}
float mul(float a, float b){
    float product;
    product=a*b;
    return product;
}
float div(float a, float b){
    float quotient;
    if(b==0){
        printf("there is error");
    }
    else{
        quotient=a/b;
        return quotient;
    }
}

int main(){
    float num1,num2;
    float result;
    char op;

    printf("simple calculator");
    printf("********************");

    printf("\nenter the operator(+,-,*,/)");
    scanf(" %c",&op);

    printf("\nenter the first number:",num1);
    scanf("%f",&num1);

    printf("\nenter the second number:",num2);
    scanf("%f",&num2);

    switch(op)
    {
        case'+': 
        result=add(num1,num2);
        break;

        case'-': 
        result=sub(num1,num2);
        break;

        case'*':
         result=mul(num1,num2);
        break;

        case'/': 
        result=div(num1,num2);
        break;

        default:
        printf("\ninvalid operation");
        result=0;

    }
    printf("\nresult is %.2f",result);
    return 0;
}
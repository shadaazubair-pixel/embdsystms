#include <stdio.h>
float add(int a, int b)//function definition for addition
{
    float sum;
    sum=a+b;//copy of num1 and num2 being added
   
    return sum;//return sum value wherever it is called

}
float sub(int a, int b){//function definition for subraction
    float diff;
    diff=a-b;
    
    return diff;
    
    
}
 float mul(int a, int b){//function definition for multiplication
    float product;
    product=a*b;
    
    return product;
    
    
}
float div(int a, int b){//function definition for division
    float quotient;
    if(b==0)
    {
        printf("there is error");
    
        return 0;
    }
    else{
        quotient=a/b;
    
    
    return quotient;

    }
}
    

int main()
{
    float num1, num2;

    float result;
    char op;
    printf("simple calculator");
    printf("*******************");
    
    printf("\nenter first integer:");
    scanf("%f",&num1);

    printf("\nenter the operator(+,-,*,/)");
    scanf(" %c",&op);


    printf("enter the second number:");
    scanf("%f",&num2);

    if(op=='+')
    {
        result=add(num1, num2);//function call where result=sum
    }
    else if(op=='-')
    {
        result=sub(num1, num2);
    }
    else if(op=='*')
    {
        result=mul(num1, num2);
    }
    else if(op=='/')
    {
        result=div(num1, num2);
    }
    else{
        printf("invalid");
    }

   
    printf("\nresult=%.2f",result);
    


    return 0;
}
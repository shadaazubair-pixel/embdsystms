#include <stdio.h>
int add(int a, int b){
    int sum;
    sum=a+b;
   
    return sum;

}
int sub(int a, int b){
    int diff;
    diff=a-b;
    
    return diff;
    
    
}
 int mul(int a, int b){
    int product;
    product=a*b;
    
    return product;
    
    
}
int div(int a, int b){
    int quotient;
    quotient=a/b;
    
    return quotient;
}

int main()
{
    int num1, num2;
    int result;
    printf("enter first integer:");
    scanf("%d",&num1);
    printf("enter the second number:");
    scanf("%d",&num2);
   result=add(num1, num2);
    printf("the sum of two nos is: %d",result);
    result=sub(num1, num2);
    printf("\ndiff of two number is%d",result);
    
    result=mul(num1, num2);
    printf("\nthe product of two nos is %d",result);
    div(num1, num2);
    printf("\nthe quotient is %d", result);
    
    


    return 0;
}
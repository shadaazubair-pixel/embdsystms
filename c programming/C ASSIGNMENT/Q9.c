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
    float pdt;
    pdt=a*b;
    return pdt;



}


float div(float a,float b){
    int quo;
    
    if(b==0){
        printf("invalid");
    }

    quo=a/b;

    return quo;

}
    


int main(){
    float a,b;
    char op;
    printf("enter two numbers:");
    scanf("%f %f",&a,&b);

    printf("enter the operator(+,-,/,*):");
    scanf(" %c",&op);


    switch(op){
        case '+':
        
        printf("sum=%.2f",add(a,b));
        break;


        case '-':
        printf("difference=%.2f",sub(a,b));
        break;


        case '*':
        printf("product=%.2f",mul(a,b));
        break;


        case '/':
        printf("quotient=%.2f",div(a,b));
        break;




        default:
        printf("\ninvalid operator");


        
        


    }

    return 0;

}
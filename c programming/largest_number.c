#include<stdio.h>
int main(){

    int num1,num2,num3,largest;

    printf("enter the 1st number:");
    scanf("%d",&num1);

    printf("enter the 2nd number:");
    scanf("%d",&num2);

    printf("enter the 3rd number:");
    scanf("%d",&num3);

    

    if(num1>num2&&num1>num3){
        largest=num1;
        printf("%d is the largest",largest);
    }

    else if(num2>num1&&num2>num3){
        largest=num2;
        printf("%d is largest number",largest);
    }

    else{
        largest=num3;
        printf("%d is the largest",largest);
    }
    return 0;

}

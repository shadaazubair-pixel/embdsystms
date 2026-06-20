#include<stdio.h>

int func(int a); //function declaration


int main(){
    int n;
    char x;
    printf("enter the number:");
    scanf("%d",&n);
    x=func(n);  //function calling
    

    if(x){
        printf("%d is a perfect number",n);
    }

    else{
        printf("%d is not perfect number",n);
    }



    return 0;

}


int func(int a){  //function definition

    int div,x,sum=0;

    for(int i=1;i<a;i++){

        div=a%i;

        if(div==0){
            sum+=i;
        }

    }

    if(sum==a){
        x=1;
    }
    else{
        x=0;
    }

    return x;
    

}
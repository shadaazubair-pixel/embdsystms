#include<stdio.h>

int GCD(int a,int b); //function declaration



int main(){
    int x,y,z;
    printf("enter two numbers:");
    scanf("%d %d",&x,&y);

    if(x<0||y<0){  //if non positive integers entered
        printf("enter only positive numbers");
    }


    else{
         z=GCD(x,y);    //function calling
         printf("GCD=%d",z);

    }

    return 0;
}


int GCD(int a,int b){   //function definition
    int d;

    if(a%b==0)
    return b;
    
    
    d=a%b;
    a=b;
    b=d;
    d=GCD(a,b);
    
    
    
    
}
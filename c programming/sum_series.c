#include<stdio.h>
int main(){


    int num1,result=0,term=1;
    printf("enter the number of terms:");
    scanf("%d",&num1);

    for(int i=1;i<=num1;i++){
        result+=term;
        term=term+i;
    }
    printf("the sum of series upto n terms is %d\n",result);

}
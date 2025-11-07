#include<stdio.h>
int main(){
    int num,sum=0;
    do{
        printf("enter the number(enter 0 to stop):");
        scanf("%d",&num);
        sum+=num;
    }while(num!=0);

    printf("sum=%d\n",sum);
    return 0;
    
    
}
#include<stdio.h>
int main(){
    int num,n,sum,a;
    printf("The armstrong numbers are:\n");

    for(n=100;n<=999;n++){
        num=n;
        sum=0;
        
        while(num>0){
            a=num%10;
            num/=10;
            a=a*a*a;
            sum+=a;

        }
        if(n==sum){
            printf("%d\n",n);
        }

       
    }
    
    return 0;
}
#include<stdio.h>
int main(){
    long n;
    int rem,sum;
    printf("enter the no:");
    scanf("%ld",&n);

    do{
        sum=0;

        while(n!=0){
            rem=n%10;
            sum+=rem;
            n/=10;


        }
        printf("%d\t",sum);
        n=sum;
    }while(n/10!=0);
    

    
    return 0;
}
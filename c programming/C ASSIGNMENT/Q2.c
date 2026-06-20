#include<stdio.h>
int main(){
    int n,i,flag=1;
    printf("enter a number:");
    scanf("%d",&n);

    for(i=2;i<n;i++){


       if(n%i==0){
            flag=0;
            break;
            
        }
        else{
            flag=1;
        }

        
    }



    if(n<=1){
        printf("enter a number greater than 1\n");

    }
    else if(flag){
        printf("%d is prime",n);
    }
    else{
        printf("%d is not prime",n);
    }
    return 0;
}
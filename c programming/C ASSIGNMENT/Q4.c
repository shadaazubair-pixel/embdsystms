#include<stdio.h>

int main(){
    int n,m=0,f=1;
    long result;
    printf("enter the number:");
    scanf("%d",&n);

    printf("%d\n",f);

    for(int i=1;i<=n;i++){
        
        result=m+f;

        printf("%ld\n",result);
        
        m=f;
        f=result;


    }

   






    return 0;
}
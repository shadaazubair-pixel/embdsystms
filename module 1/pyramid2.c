#include<stdio.h>
int main(){
    int i,j,n;
    printf("enter the number:");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        for(j=i;j<=n+1-i;j++){
            printf("%d",n+1-i);
        }
        printf("\n");
        /* code */
    }
    return 0;
    
}
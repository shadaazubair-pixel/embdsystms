#include<stdio.h>
int main(){
    int i,j,n,m=1;
    printf("enter the number:");
    scanf("%d",&n);
    for(i=1;i<=5;i++){
        for(j=1;j<=i;j++){
            printf("%3d",m);
            m++;
        }
        printf("\n");
    }
    return 0;
}
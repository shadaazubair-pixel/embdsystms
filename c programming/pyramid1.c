#include<stdio.h>
int main(){
    int i,j,n;
    printf("enter the number of lines:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){


            printf("%3d",n+1-j);
            
            }


            
           printf("\n");
            

        }
         
        
    
    return 0;

}
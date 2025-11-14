#include<stdio.h>
int main(){
    int i,j,rows,space,p=1;
    printf("enter the rows:");
    scanf("%d",&rows);


    for(i=1;i<=rows;i++){
        for(space=rows-i;space>=1;space--){
            printf("   ");

        }
        for(j=1;j<=i;j++){
            printf("%3d",i+i);
         
            
       
          
        }
        printf("\n");
    }
    return 0;
}
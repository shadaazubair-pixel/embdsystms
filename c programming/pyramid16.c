#include<stdio.h>
int main(){
    int i,j,rows,space;
    printf("enter the rows:");
    scanf("%d",&rows);


    for(i=1;i<=rows;i++){
        for(space=rows-i;space>=1;space--){
            printf(" ");

        }
        for(j=1;j<=i;j++){
            printf("%d ",j);
          
        }
        printf("\n");
    }
    return 0;
}
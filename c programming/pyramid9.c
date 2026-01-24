#include<stdio.h>
int main(){
    int i,j,rows,space;
    printf("enter the number of rows:");
    scanf("%d",&rows);

    for(i=1;i<=rows-1;i++){
        for(space=1;space<=rows-i;space++){
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }



    for(i=rows;i>=1;i--){
        for(space=1;space<=rows-i;space++){
            printf(" ");
        }
        for(j=2*i-1;j>=1;j--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
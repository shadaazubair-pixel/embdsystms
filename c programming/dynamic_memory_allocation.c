#include<stdio.h>
#include<stdlib.h>
int main(){
    int a=10;
    int *ptr=&a;
    int *p;
    int n;

    printf("enter the number of integers to be stored=");
    scanf("%d",&n);

    p=(int *)malloc(n*sizeof(int));

    if(p==NULL){
        printf("memory allocation failed\n");
        return 1;
    }
    
   
    for(int i=0;i<n;i++){
        printf("enter the %dst integer:",i+1);
        scanf("%d",p+i);

    }
    for(int i=0;i<n;i++){
        printf("the integers stored are %d\n",*(p+i));
    }
    free(p);
    return 0;
}
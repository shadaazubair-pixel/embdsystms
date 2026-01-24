#include<stdio.h>
int largest(int a, int b){
   return  a>b?a:b;
    
}



int main(){
    int x,y;
    printf("enter the nos:");
    scanf("%d %d",&x,&y);
    printf("the largest no: is %d\n",largest(x,y));

    return 0;
}
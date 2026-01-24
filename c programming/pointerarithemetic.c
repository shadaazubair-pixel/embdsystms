#include<stdio.h>

int main(){
    int arr[5]={10,20,30,40,50};
    int *arrptr=arr;
    int x=(*arrptr)++;
    printf("arrptr=%d\n",(*arrptr)); // arrptr=arrptr+1
    printf("x=%d\n",x);  //x=arrrptr

    return 0;
}
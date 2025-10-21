#include<stdio.h>
int main(){
    int arr[5]={1,2,3,4,5};
    int *arrptr=arr;

    for(int i=0;i<5;i++){
        printf("the value of[%d]=%d and the address is %p\n",i,*(arrptr+i)+5,arrptr+i);
    }
    return 0;

}
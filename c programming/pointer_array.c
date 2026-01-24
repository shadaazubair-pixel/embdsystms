#include<stdio.h>
int arr[10]={10,20,30,40,50,60,70,80,90,100};
int *ptr2=arr;//int pointer to array
int main(){
    for(int i=0;i<10;i++){
        printf("value of arr[%d]=%d and the address of array=%p\n",i,*(ptr2+i),(ptr2+i));
    
    }



   
        
    return 0;
}
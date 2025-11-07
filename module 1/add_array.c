#include<stdio.h>
int main(){

    int arr[5],sum=0;
    for(int i=0;i<5;i++){
        
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("the sum of array is %d\n",sum);
    return 0;
}
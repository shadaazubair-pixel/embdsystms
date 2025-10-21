#include<stdio.h>
int main(){

    int arr[5]={10,20,30,40};
    int *p=arr+2;

    printf("value of *p=%d\n",*p);
    int x=--(*p);
    printf("the value of *p=%d\n",*p);
    printf("the value of x=%d\n",x);

    return 0;


}
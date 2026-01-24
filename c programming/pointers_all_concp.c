#include<stdio.h>
int main(){
    int a=10;
    int *ptr=&a;

    printf("value of a=%d\n",*ptr);
    printf("address of a=%p\n",ptr);
    *ptr=20;
    printf("value of a=%d\n",a);
    printf("*(ptr+1)=%d\n",*(ptr+1));  //prints junk value as it prints value in another addresss
    printf("*ptr=%d\n",*ptr);
    printf("*(ptr)+1=%d\n",*(ptr)+1);

    return 0;

}
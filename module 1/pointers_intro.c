#include<stdio.h>
int a=10;
int*ptr =&a;

char b='D';
char *ptr1=&b;

int main(){
    printf("value of a=%d\n",a);
    a=20;
    printf("Address of a=%p\n",&a);//checking address of a
    printf("address of variable using pointer p=%p\n",ptr);//value in p

    printf("value of inside address stored in p=%d\n",*ptr);
    printf("address of p=%p\n",&ptr);

    printf("size of a=%d bytes\n",sizeof(a));
    printf("size of pointer=%d bytes\n",sizeof(ptr));

    printf("size of char b=%d bytes\n",sizeof(b));
    printf("size of ptr1=%d bytes",sizeof(ptr1));//since address is being stored will get 8 bytes



    return 0;
}
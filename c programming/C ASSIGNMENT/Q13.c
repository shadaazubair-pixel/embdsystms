#include<stdio.h>
#include<string.h>

int main(){

    int i,len,temp;
    char str[20];

    printf("enter the string:");
    gets(str);

    printf("The string before reversing:%s\n",str);


    len=strlen(str);

    for(i=0;i<len/2;i++){

        temp=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=temp;


    }

    printf("The string reversed:%s",str);





    return 0;
}
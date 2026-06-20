#include<stdio.h>
#include<string.h>

int main(){

    int i,len,flag=0;
    char s[20];
    printf("enter the string:");
    gets(s);

    len=strlen(s);

    for(i=0;i<len/2;i++){

        if(s[i]!=s[len-1-i]){
            flag=1;
            break;
            
        }
    }

    if(flag){
        printf("The string entered is not palindrome ");
    }

    else
    printf("The string entered is palindrome");
        

    return 0;
}
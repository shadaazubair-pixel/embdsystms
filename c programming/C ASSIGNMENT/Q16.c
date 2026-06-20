#include<stdio.h>
int main(){

    char str[30];
    int i;

    printf("enter the string:");
    fgets(str,sizeof(str),stdin);

    for(i=0;str[i]!=0;i++){
        if(str[i]>=65 && str[i]<=90){
            str[i]=str[i]+32;
        }


    }


    printf("new string=%s",str);














    return 0;
}
#include<stdio.h>
#include<string.h>

int main(){

    int i,a,flag=0;
    char str[100];
    char x[26]={0};
    int pos;
    printf("enter the string:");
    fgets(str, sizeof(str), stdin);


    



    

    for(i=0;str[i]!='\0';i++){

        if (str[i]>='A' && str[i]<='Z')

        {
            pos=str[i]-'A';
            x[pos]=1;
            
        }

        else if(str[i]>='a' && str[i]<='z'){
            pos=str[i]-'a';
            x[pos]=1;
        }
    }


    
        for(i=0;i<26;i++){
            if(x[i]==0){
                flag=1;
                break;
            }

        

        }


        if(flag){
            printf("the string is not pangram");

        }
        
        else{
            printf("the string is pangram");
        }

       

    

    


    return 0;
}
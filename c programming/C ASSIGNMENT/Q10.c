#include<stdio.h>



int main(){

    int i=0,result=0,dig,flag=0;
    char str[20];
    printf("enter the number:");
    scanf("%s",str);

    

    for(i=0;str[i]!='\0';i++){

        dig=str[i]-'0';


        if(dig<0){
            flag=1;
            break;
            
        }

        result=result*10+dig;

        
        



    }
    if(flag){
        printf("enter positive numbers only");

    }

    else{

        printf("result=%d",result);
        
    }
    
    

    return 0;

}
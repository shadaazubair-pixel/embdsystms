#include<stdio.h>

int main(){
    float tempereture,celsius,farenheit;
    int choice;

    printf("1. convert c to f\n");
    printf("2. convert f to c\n");
    printf("enter your tempereture\n");
    scanf("%f",&tempereture);
    printf("enter your choice:\n");
    scanf("%d",&choice);
    


    if(choice==1){
        farenheit=(tempereture*(9.0/5.0)+32);
        printf("the tempereture is %f F\n",farenheit);

    }
    else{
        celsius=(tempereture-32)*5.0/9.0;
        printf("the tempereture is %f celsius\n",celsius);

    }
    

    return 0;
}
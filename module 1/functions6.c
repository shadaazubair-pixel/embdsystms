#include<stdio.h>
void findnum(int x){
    if(x%2==0){
        printf("the number is even");
        return;

    }
    else{
        printf("the number is odd");
    }
}


int main(){
    int a;
    printf("enter the number:");
    scanf("%d",&a);
    findnum(a);

return 0;

}
#include<stdio.h>

void PrintBin(int n){
    int mask;
    for(int i=31;i>=0;i--){
        mask=1<<i;
        if(n&mask){
            printf("1");

        }
        else{
            printf("0");
        }
    }
    printf("\n");
    
}
void SetBit(int n,int pos){
    int mask=1<<pos;
    n=n|mask;
    PrintBin(n);

}







int main(){
    int a,pos;
    printf("Enter a number:");
    scanf("%d",&a);
    PrintBin(a);
    printf("enter the bit position:");
    scanf("%d",&pos);

    SetBit(a,pos);
    return 0;
}
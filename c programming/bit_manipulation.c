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
}

void SetBit(int n,int pos){
    int mask=1<<pos;
    n=n|mask;
    PrintBin(a);

}
void ClearBit(int n,int pos){
    int mask=~(1<<pos);
    n=n&mask;
    PrintBin(a);
}


int main(){
    int a,pos;
    printf("enter an integer:");
    scanf("%d",&a);
    PrintBin(a);
    printf("enter the bit position:");
    scanf("%d",&pos);
    SetBit(a);
    ClearBit(a);

    return 0;


}
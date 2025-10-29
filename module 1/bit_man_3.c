#include<stdio.h>

void PrintBin(int n){
    int mask,count=0;
    int count1=0;
    for(int i=7;i>=0;i--){
        mask=1<<i;
        if(n&mask){
            printf("1");
            count++;

        }
        else{
            printf("0");
            count1++;
        }
    }
    printf("\n");
    printf("the number of 1's=%d\n",count);
    printf("the number of 0's=%d\n",count1);
    
}
void SetBit(int n,int pos){
    int count=0;
    int count1=0;
    int mask=1<<pos;
    n=n|mask;
    PrintBin(n);

    


}







int main(){
    int a,pos,count=0,b;
    printf("Enter a number:");
    scanf("%d",&a);
    PrintBin(a);
    printf("enter the bit position:");
    scanf("%d",&pos);

    SetBit(a,pos);
    
    return 0;
    
}
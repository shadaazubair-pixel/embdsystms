#include<stdio.h>
int PrintBin(int x){
    int mask;
    

    for(int i=7;i>=0;i--){
        mask=1<<i;
        
        if(x&mask){
            printf("1");
        }
        else{
            printf("0");
        }

    }
    

    printf("\n");
    return x;
}


int SetBit(int y, int pos){
    int mask=1<<pos;
    y=y|mask;
    PrintBin(y);


    return y;
    
    
}

 int ClearBit(int x,int pos1){
    int mask=~(1<<pos1);
    x=x&mask;
    PrintBin(x);
    return x;
}

int ToggleBit(int x,int pos2){
    int mask=1<<pos2;
    x=x^mask;
    PrintBin(x);
    return x;
}



int main(){
    int a,pos=2,pos1=5,pos2=0;
    printf("enter the number:");
    scanf("%d",&a);
    PrintBin(a);

    a=SetBit(a,pos);
    
    a=ClearBit(a,pos1);

    a=ToggleBit(a,pos2);

    printf("the modified value is %d\n",a);

    

    return 0;
}

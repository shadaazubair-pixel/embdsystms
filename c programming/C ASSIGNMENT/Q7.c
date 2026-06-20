#include<stdio.h>

void func(long n,int count[]){

    int a;
    

    while(n){
        a=n%10;
        count[a]++;
        n/=10;
    }
}


int main(){
    long n;
   int freq[10]={0,0,0,0,0,0,0,0,0,0};
    printf("enter an integer:");
    scanf("%ld",&n);

    func(n,freq);

    for(int i=0;i<10;i++){
        printf("The no: of %d's in the %ld is %d",i,n,freq[i]);
        printf("\n");
    }

    

    return 0;
}
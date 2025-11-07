#include<stdio.h>
int main(){

    int arr[5]={1,34,56,23,66};
    int largest,smallest;
    smallest=largest=arr[0];
    for(int i=1;i<5;i++){
        if(arr[i]>largest){
            largest=arr[i];
            
            
        }
        if(arr[i]<smallest){
            smallest=arr[i];
            
        }
        
        

    
    }
    printf("the largest is %d\n",largest);
    printf("the smallest is %d\n",smallest);
    
    return 0;
}
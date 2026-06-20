#include<stdio.h>
int main(){
    int x;
    printf("enter the size of array:");
    scanf("%d",&x);

    int arr[x];

    for(int i=0;i<x;i++){
        printf("enter arr[%d]:",i);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<x;i++){

        for(int j=i+1;j<x-1;j++){
            if(arr[i]==arr[j]){

                for(int k=i;k<x-1;k++){
                    arr[k]=arr[k+1];
                }
                x--;
                j--;

            }
        }
        

    }

    for(int i=0;i<x;i++){
        printf("arr[%d]=%d\n",i,arr[i]);
    }

    





    return 0;
}
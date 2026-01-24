#include<stdio.h>
void scndlarge(int x, int val[]){       //function definition
    int large,scndlarge,small;
    large=small=val[0];
    
    
    for(int i=1;i<x;i++){            //finding smallest and largest elemnts
        if(val[i]>large){
            large=val[i];
        }

        if(val[i]<small){
            small=val[i];
        }
        


    }
    printf("the largest number is %d\nThe smallest is %d\n",large,small);

    

    for(int i=1;i<x;i++){      //finding second largest element
        if(large>val[i]&&small<val[i]){
            scndlarge=val[i];
            
        }
    }
    printf("the second largest is %d\n",scndlarge);

}
int main(){
    int x,arr[x];
    printf("enter the size of array");
    scanf("%d",&x);
     for(int i=0;i<x;i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);

    }

    printf("the elements of array are:");        //printing the array elements
    for(int i=0;i<x;i++){
        
        printf("%d\t",arr[i]);
    }
    printf("\n");

    scndlarge(x,arr);         //function call
    return 0;

}
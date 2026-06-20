#include<stdio.h>
int main(){
    int arr[10],n,i,pos,temp;
    char direction;

    printf("enter no:of elements:");
    scanf("%d",&n);

    printf("enter no:of rotations:");
    scanf("%d",&pos);

    printf("enter direction of rotation:");
    scanf(" %c",&direction);

    if(pos>n){
        pos%=n;

    }

    for(i=0;i<n;i++){
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]);

    }

    if(direction=='l' || direction=='L'){
        for(int k=0;k<pos;k++){
            temp=arr[0];

            for(i=0;i<n-1;i++){
                arr[i]=arr[i+1];
            }
            arr[n-1]=temp;
        }

    }


     if(direction=='r' || direction=='R'){
        for(int k=0;k<pos;k++){
            temp=arr[n-1];

            for(i=n-1;i>0;i--){
                arr[i]=arr[i-1];
            }
            arr[0]=temp;
        }

    }

    printf("after rotation:");

    for(i=0;i<n;i++){
        printf("\narr[%d]=%d",i,arr[i]);


    }

    return 0;

}
#include<stdio.h>
int main(){
int arr[10],temp[10],n,i,j=0;

printf("Enter size of array:");
scanf("%d",&n);

printf("Enter array elements:\n");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}

for(i=0;i<n;i++){
    if(arr[i]<0){
    temp[j]=arr[i];
    j++;
    }
}

for(i=0;i<n;i++){
            if(arr[i]>=0){
        temp[j]=arr[i];
    j++;
        }
}

printf("Rearranged array:\n");
for(i=0;i<n;i++){
printf("%d ",temp[i]);
}

return 0;
}
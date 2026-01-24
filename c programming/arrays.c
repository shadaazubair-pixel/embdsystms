#include<stdio.h>
int main(){


int arr[5];

for(int i=0;i<5;i++){
    printf("arr[%d]=",i);
    scanf("%d",&arr[i]);

}
 printf("the arrays elements are:\t");
for(int i=0;i<5;i++){
   
    printf("%d\t",arr[i]);
}

return 0;
}
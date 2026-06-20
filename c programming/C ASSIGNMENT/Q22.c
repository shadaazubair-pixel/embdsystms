#include<stdio.h>
int main(){
int arr[10],n,i,largest,smallest,secondlrg,secondsmll;

printf("Enter the no. of elements: ");
scanf("%d",&n);


for(i=0;i<n;i++){
printf("Enter arr[%d]: ",i);
scanf("%d",&arr[i]);
}

if(arr[0]>arr[1]){

    largest=arr[0];
    secondlrg=arr[1];
    smallest=arr[1];
    secondsmll=arr[0];
}

else{

    largest=arr[1];
    secondlrg=arr[0];
    smallest=arr[0];
    secondsmll=arr[1];
}


for(i=2;i<n;i++){

    if(arr[i]>largest){
    secondlrg=largest;
    largest=arr[i];
}
else if(arr[i]>secondlrg&&arr[i]!=largest){
    secondlrg=arr[i];
}

if(arr[i]<smallest){
    secondsmll=smallest;
    smallest=arr[i];
}
else if(arr[i]<secondsmll&&arr[i]!=smallest){


    secondsmll=arr[i];
}
}

printf("\nLargest=%d",largest);
printf("\nSecond Largest=%d",secondlrg);
printf("\nSmallest=%d",smallest);
printf("\nSecond Smallest=%d",secondsmll);

return 0;
}
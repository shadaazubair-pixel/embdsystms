#include<stdio.h>
#include<string.h>

int main(){
int n,i=0,a,len;
char str[20],temp;

printf("Enter the number:");
scanf("%d",&n);

if(n==0){
str[i]='0';
i++;
}

if(n<0){
str[i]='-';
i++;
n=-n;
}

while(n!=0){
a=n%10;
str[i]=a+'0';
i++;
n/=10;
}

str[i]='\0';

int start=(str[0]=='-')?1:0;
len=strlen(str);

for(i=start;i<(start+len)/2;i++){
temp=str[i];
str[i]=str[len-1-(i-start)];
str[len-1-(i-start)]=temp;
}

printf("The required string is %s",str);

return 0;


}
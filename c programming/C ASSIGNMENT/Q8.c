#include<stdio.h>

void convert(int n,int base){


char result[32];
int i=0,rem;

while(n>0){
rem=n%base;



if(rem<10){
    result[i]=rem+'0';

}

else
result[i]=rem-10+'A';
i++;
n=n/base;
}

printf("Converted number:");
for(i=i-1;i>=0;i--){
printf("%c",result[i]);
}
}

int main(){
int n,base;

printf("Enter decimal number:");
scanf("%d",&n);

printf("Enter base(2-16):");
scanf("%d",&base);

if(base<2||base>16){



printf("Invalid base");
return 0;


}

convert(n,base);

return 0;
}
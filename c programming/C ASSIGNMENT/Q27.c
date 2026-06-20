#include<stdio.h>

struct complex{
int real;
int imag;
};




struct complex add(struct complex c1,struct complex c2){


struct complex sum;
sum.real=c1.real+c2.real;
sum.imag=c1.imag+c2.imag;
return sum;


}





void func(struct complex c){


printf("%d+%di",c.real,c.imag);
}

int main(){
struct complex c1,c2,sum;


printf("Enter real and imaginary part of first complex number:");
scanf("%d%d",&c1.real,&c1.imag);

printf("Enter real and imaginary part of second complex number:");
scanf("%d%d",&c2.real,&c2.imag);

sum=add(c1,c2);
printf("sum=");
func(sum);

return 0;



}
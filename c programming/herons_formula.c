#include<stdio.h>
#include<math.h>
int main(){
    float s,a,b,c,area;
    
    printf("enter the value of a=");
    scanf("%f",&a);

    printf("enter the value of b=");
    scanf("%f",&b);

    printf("enter the value of c=");
    scanf("%f",&c);

    s=(a+b+c)/2;
    printf("the semiperimeter is =%.2f\n",s);

    area=sqrt(s*(s-a)*(s-b)*(s-c));

    printf("area of triangle=%.2f",area);

    return 0;


    

}
/*#include<stdio.h>
int main(){
    int a,square,cube;
    printf("enter the no:");
    scanf("%d",&a);
    square=a*a;
    cube=a*a*a;
    printf("the square of the number is %d\n",square);
    printf("the cube of the number is %d\n",cube);
    return 0;


}
*/

#include<stdio.h>
#include<math.h>
int main(){
    double base,exponent,result;

printf("enter the base:");
scanf("%lf",&base);

printf("enter the exponent:");
scanf("%lf",&exponent);

result=pow(base,exponent);

printf("%.2lf raised to %.2lf is %.2lf\n",base,exponent,result);
return 0;

}


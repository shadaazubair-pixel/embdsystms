#include<stdio.h>
int main(){
    int a,b,c;

    printf("a=");
    scanf("%d",&a);

    printf("b=");
    scanf("%d",&b);
    c=a;
    a=b;
    b=c;

    printf("afer swapping\n");

    printf("the value of a is %d\n",a);
    printf("the value of b=%d\n",b);
    printf("the value of c is %d\n",c);

    return 0;

    
    


}
#include<stdio.h>
/*void drawline();  //function declaration
int main(){
    drawline();   //function call
    return 0;
}
void drawline(){           //function definition
    for(int i=0;i<=69;i++){
        printf("-");
    }
}*/

int sum(int x,int y){
    int result;
    result=x+y;
    
}
int main(){
    int a,b,s;
    printf("enter the nos:");
    scanf("%d %d",&a,&b);

    s=sum(a,b);
    printf("the sum of %d and %d is %d\n",a,b,s);
    return 0;
}
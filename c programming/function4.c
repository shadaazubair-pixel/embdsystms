#include<stdio.h>

int cmpdate(int d1,int d2,int m1,int m2,int y1,int y2){
    if(y1>y2)
    return 1;

    if(y1<y2)
    return -1;

    if(m1>m2)
    return 1;

    if(m1<m2)
    return -1;

    if(d1>d2)
    return 1;

    if(d1<d2)
    return -1;

    return 0;
}






int main(){
    int d1,d2,m1,m2,y1,y2,result;
    printf("enter the first date:");
    scanf("%d/%d/%d",&d1,&m1,&y1);

    printf("enter the second date:");

    scanf("%d/%d/%d",&d2,&m2,&y2);

    result=cmpdate(d1,d2,m1,m2,y1,y2);

    if(result==0){
        printf("both are same date");
    }
    else if(result>0){
        printf("the date is earlier");

    }
    else{
        printf("the date is later\n");
    }

    

    return 0;


}
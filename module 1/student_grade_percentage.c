#include<stdio.h>

int main(){

    float m1,m2,m3,m4,total,per;
    char grade;
    printf("enter the marks of four subjects:");
    scanf("%f %f %f %f",&m1,&m2,&m3,&m4);

    total=m1+m2+m3+m4;
    per=(total/400)*100;

    if(per>=85){
        grade='A';

    }
    else if(per>=70){
        grade='B';

    }
    else if(per>=50){
        grade='C';
    }
    else if(per>=40){
        grade='D';
    }
    else{
        grade='E';
    }
    printf("The student got %.2f percentage and the grade obtained is %c",per,grade);
    return 0;
    
}
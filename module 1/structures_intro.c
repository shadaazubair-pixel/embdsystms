/*#include<stdio.h>
struct marks {
    int maths;
    float science;
    int english;

}Nithin={90,58.5,88}, nikhil={77,77,90};
int main(){
    //struct marks Nithin={90,58.5,88};
    //struct marks nikhil={77,77,90};
    printf("maths=%d, science=%.2f,english=%d\n",Nithin.maths,Nithin.science,Nithin.english);
    printf("maths=%d, science=%.2f,english=%d\n",nikhil.maths,nikhil.science,nikhil.english);
    return 0;
}*/


// alternate syntax
#include<stdio.h>
typedef struct {
    int maths;
    float science;
    int english;

}student;

int main(){
    student nithin={90,99,90};
    printf("maths=%d,science:%f,english:%d",nithin.maths,nithin.science,nithin.english);
    return 0;
}
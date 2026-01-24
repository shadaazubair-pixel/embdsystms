/*#include<stdio.h>
int main(){
    int i,j,rows,m;
    printf("rows=");
    scanf("%d",&rows);

    for(i=rows;i>=1;i--){



    
        for(j=rows;j>=i;j--){
            
            printf("%3d",j);
            
            
            
            

        }
        
        printf("\n");
    }

    return 0;
}*/



#include<stdio.h>
int main(){
    int i,j,rows,m;
    printf("rows=");
    scanf("%d",&rows);

    for(i=rows;i>=1;i--){



    
        for(j=rows;j>=i;j--){
            
            printf("%3d",i);
            
            
            
            

        }
        
        printf("\n");
    }

    return 0;
}
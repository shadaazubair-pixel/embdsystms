#include<stdio.h>
typedef struct{
    char title[50];
    char author[50];
    int price;

}Book;

int main(){
    
    
    Book Book1={"Deception point","DanBrown",200};

    printf("title: %s,author: %s,price: %d\n", Book1.title,Book1.author,Book1.price);

    Book Book2={"Wings of fire", "APJ Abdul Kalam", 300};
    printf("title: %s,author: %s,price: %d\n", Book2.title,Book2.author,Book2.price);

    Book Book3={"Story of my life", "Helen Keller", 350};
    printf("title: %s,author: %s,price: %d\n", Book3.title,Book3.author,Book3.price);

    Book expensive=Book3;

    if(Book2.price>Book3.price){
        printf("The expensive book is :title: %s,author: %s,price: %d\n", Book2.title,Book2.author,Book2.price );
    }


            else if(Book1.price>Book3.price){
                printf("The expensive book is :title: %s,author: %s,price: %d\n", Book1.title,Book1.author,Book1.price );
    
    }
    else{
        printf("The expensive book is :title: %s,author: %s,price: %d\n", Book3.title,Book3.author,Book3.price );
    }
    
    Book lowest_price=Book1;
    if(Book1.price>Book2.price){
        printf("The lowest priced book is :title: %s,author: %s,price: %d\n", Book2.title,Book2.author,Book2.price );
    }
    else if(Book1.price>Book3.price){
        printf("The lowest priced book is :title: %s,author: %s,price: %d\n", Book3.title,Book3.author,Book3.price );
    }
    else{
        printf("The lowest priced book is :title: %s,author: %s,price: %d\n", Book1.title,Book1.author,Book1.price );
    }

    
    return 0;

}
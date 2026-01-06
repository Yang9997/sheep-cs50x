#include<stdio.h>
#include<cs50.h>
int main(void){
    // int x = get_int("What is x?");
    // int y = get_int("What is y?");

    // if (x<y){
    //     printf("x is less than y.\n");
    // }

    // return 0;

    int x = get_int("What is x?");
    int y = get_int("what is y?");

    if(x>y){
        printf("x is greater than y.\n");
    }
    else if(y>x){
        printf("x is less than y.\n");
    }
    else{
        printf("x is equal to y.\n");
    }
}
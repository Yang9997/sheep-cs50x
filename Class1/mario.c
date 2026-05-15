#include<stdio.h>
#include<cs50.h>
int main(void){
    // for(int i = 0;i<4;i++){
    //     printf("?");
    // }

    // printf("\n");
    // return 0;
    // for(int i=0;i<3;i++){
    //     printf("#\n");
    // }

    // // printf("\n");
    // return 0;

    // int count = get_int("Enter your number: ");
    int count;
    do{
        // 获得长宽
        count = get_int("Enter the size: ");
    }while(count<1);
    // 打印砖头
    for (int i = 0;i<count;i++){
        for(int j = 0;j<count;j++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
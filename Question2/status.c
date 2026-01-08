#include<stdio.h>
#include<cs50.h>
int main(int args,string argv[]){
    if(args != 2)
    {
        printf("Missing command-line arguments.\n");
        return 1;
    }
    printf("Hello, %s.\n",argv[1]);
    return 0;
}

// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int bigFlag = 0;
    int smallFlag = 0;
    int numFlag = 0;
    int otherFlag = 0;
    int flag = 0;

    for(int i = 0;i<strlen(password);i++){
        if(bigFlag == 0 && isupper(password[i]))
            bigFlag = 1;
        else if(smallFlag == 0 && islower(password[i]))
            smallFlag = 1;
        else if(numFlag == 0 && isdigit(password[i]))
            numFlag = 1;
        else if(otherFlag == 0 && ispunct(password[i]))
            otherFlag = 1;

        if(otherFlag == 1 &&bigFlag == 1 &&smallFlag == 1 && numFlag == 1){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        return true;
    }
    return false;
}

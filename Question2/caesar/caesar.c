#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string s);
int rotate(string s);
void ciphertext(int n,string s);

int main(int args, string argv[])
{
    if (args!=2 || !only_digits(argv[1])){
        // printf("%i\n",args);
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int number = rotate(argv[1]);
    printf("%i\n",number);
    string s = get_string("plaintext: ");
    ciphertext(number,s);
    return 0;
}

bool only_digits(string s){
    for(int i = 0;i<strlen(s);i++){
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}
int rotate(string s){
    int number = 0;
    for(int i = 0;i<strlen(s);i++){
        number*=10;
        number+=s[i]-48;
    }
    return number;
}
void ciphertext(int n,string s){
    printf("ciphertext: ");
    for(int i = 0;i<strlen(s);i++){
        if(islower(s[i])){
            printf("%c",96+(s[i]-96+n)%26);
        }else if(isupper(s[i])){
            printf("%c",64+(s[i]-64+n)%26);
        }
        else{
            printf("%c",s[i]);
        }
    }
    printf("\n");
}

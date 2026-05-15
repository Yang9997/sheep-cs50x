#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

bool isMatchNumber(string s);
bool isAlpha(string s);
bool isDifferent(string s);
void printCiphertext(string s1,string s2);

int main(int argc, string argv[])
{

    if(argc !=2 ){
        // 两个参数
        printf("Usage: ./substitution key\n");
        return 1;
    }else if(!isAlpha(argv[1])){
        // 是字母
        printf("Key must be alphabet.\n");
        return 1;
    }else if(!isMatchNumber(argv[1])){
        // 26个字母
        printf("Key must contain 26 characters.\n");
        return 1;
    }else if(!isDifferent(argv[1])){
        // 字母都不同
        printf("Every alphabet must be different.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    printCiphertext(argv[1],plaintext);

    return 0;
}

bool isMatchNumber(string s){
    if(strlen(s)!=26){
        return false;
    }
    return true;
}

bool isAlpha(string s){
    for(int i = 0;i<strlen(s);i++){
        if(!isalpha(s[i])){
            return false;
        }
    }
    return true;
}

bool isDifferent(string s){
    for(int i = 0;i<strlen(s);i++){
        for(int j = i+1;j<strlen(s);j++){
            if(toupper(s[i])==toupper(s[j])){
                return false;
            }
        }
    }
    return true;
}

void printCiphertext(string s1,string s2){
    printf("ciphertext: ");
    int temp = 0;
    for(int i = 0;i<strlen(s2);i++){
        if(isupper(s2[i])){
            temp = s2[i]-65;
            printf("%c",toupper(s1[temp]));
        }else if(islower(s2[i])){
            temp = s2[i] -97;
            printf("%c",tolower(s1[temp]));
        }else{
            printf("%c",s2[i]);
        }
    }
    printf("\n");
}

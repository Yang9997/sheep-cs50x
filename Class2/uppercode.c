// #include<stdio.h>
// #include<cs50.h>
// #include<string.h>
// int main(void){
//     string s = get_string("Before: ");
//     printf("After: ");

//     for(int i = 0;i<strlen(s);i++){
//         if(s[i]<='z'&&s[i]>='a'){
//             // 小写转大写
//             printf("%c",s[i]-32);
//         }
//         else{
//             printf("%c",s[i]);
//         }
//     }
//     printf("\n");

//     return 0;
// }

#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
int main(void){
    string s = get_string("Before: ");
    printf("After: ");
    for(int i = 0;i<strlen(s);i++){
            printf("%c",toupper(s[i]));
    }

    printf("\n");
    return 0;
}

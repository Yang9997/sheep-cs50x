#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    // printf("%i letters\n",letters);
    int words = count_words(text);
    // printf("%i words\n",words);
    int sentences = count_sentences(text);
    // printf("%i sentences\n",sentences);

    double L = letters/(1.0*words)*100;
    double S = sentences/(1.0*words)*100;
    double index_temp = 0.0588*L-0.296*S-15.8;
    // printf("\n%f\n",index_temp);
    int index = round(index_temp);

    if(index>16){
        printf("Grade 16+\n");
    }else if(index < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %i\n",index);
    }
}

int count_letters(string s){
    int letters = 0;
    for(int i = 0;i<strlen(s);i++){
        if( (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
            letters++;
        }
    }

    return letters;
}
int count_words(string s){
    int words = 1;
    for(int i = 0;i<strlen(s);i++){
        if(s[i]==' '){
            words ++;
        }
    }
    return words;
}

int count_sentences(string s){
    int sentences = 0;
    for(int i = 0;i<strlen(s);i++){
        if(s[i] == '.'||s[i]=='!'||s[i]=='?'){
            sentences ++;
        }
    }
    return sentences;
}

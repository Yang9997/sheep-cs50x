#include <cs50.h>
#include <ctype.h>

#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
void printWinner(int score1, int score2);
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printWinner(score1, score2);
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    int temp = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            temp = word[i] - 65;
            // printf("temp = %i\n",temp);
            score += POINTS[temp];
        }
        else if (islower(word[i]))
        {
            temp = word[i] - 97;
            // printf("temp = %i\n",temp);
            score += POINTS[temp];
        }
        // printf("%i\n",score);
    }
    return score;
}
void printWinner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

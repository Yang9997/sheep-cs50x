#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max voters and candidates
// 最大选民人数
#define MAX_VOTERS 100
// 最大候选人数
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            // 判断是不是投了没有的名字
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        // 计算各个人获得第一的票数
        tabulate();

        // Check if election has been won
        // 是否有赢家，有的话打印
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // 无赢家
        // Eliminate last-place candidates
        // 找出第一偏好中票数最少的
        int min = find_min();
        // 是否所有目前留存的候选人是平票
        bool tie = is_tie(min);

        // If tie, everyone wins
        //  如果平票，打印所有人
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        // 删掉票数最少的候选人，票数里面也要清掉姓名置""
        eliminate(min);

        // Reset vote counts back to zero
        // 各个候选人票数全置0
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
//
bool vote(int voter, int rank, string name)
{
    // TODO
    for (int i = 0; i < candidate_count ; i++)
    {
        // 有名字，有效。
        if (strcmp(candidates[i].name, name) == 0)
        {
            // 排第rank+1的是候选人名字中的第i+1个
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    for (int i = 0; i < voter_count; i++)
    {
        if (!candidates[preferences[i][0]].eliminated)
            candidates[preferences[i][0]].votes++;
        else if (!candidates[preferences[i][1]].eliminated)
            candidates[preferences[i][1]].votes++;
        else
            candidates[preferences[i][2]].votes++;
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    int temp_votes = 0;
    string temp_name;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > temp_votes)
        {
            temp_votes = candidates[i].votes;
            temp_name = candidates[i].name;
            if (temp_votes > voter_count / 2)
            {
                printf("%s\n",candidates[i].name);
                return true;
            }
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int temp = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
    {
        if (temp > candidates[i].votes && !candidates[i].eliminated)
            temp = candidates[i].votes;
    }
    return temp;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes!=min)
            {
                return false;
            }
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)\
    {
        if (candidates[i].votes == min)
            candidates[i].eliminated = true;
    }
    return;
}

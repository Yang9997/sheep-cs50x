# Round1
```C
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
            // 判断是不是投重了或者投了没有的名字
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }
    // test
    // for (int i = 0; i <voter_count; i++)
    //     {
    //         for (int j =0; j < candidate_count; j++)
    //         {
    //             printf("%d ",preferences[i][j]);
    //         }
    //         printf("\n");
    //     }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        // 计算各个人获得第一的票数
        tabulate();

        // Check if election has been won
        // 是否有赢家，有的话打印
        bool won = print_winner();
        // test
        // for (int i = 0; i < candidate_count; i++)
        // {
        //     printf("Name: %s, votes: %i, eliminate: %i\n",candidates[i].name,candidates[i].votes,candidates[i].eliminated);
        // }
        // for (int i = 0; i <voter_count; i++)
        // {
        //     for (int j =0; j < candidate_count; j++)
        //     {
        //         printf("%d ",preferences[i][j]);
        //     }
        //     printf("\n");
        // }
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
        //  如果平票，打印所有人
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
            preferences[voter][i] = rank;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < voter_count; j++)
        {
            if (preferences[j][i] == 0)
            {
                candidates[i].votes++;
            }
        }
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
        if (temp > candidates[i].votes)
            temp = candidates[i].votes;
    }
    return temp;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    if (min * candidate_count == voter_count)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (min == candidates[i].votes)
            candidates[i].eliminated = true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    // string temp;
    for (int i = 0; i < candidate_count; i++)
    {
        // 该候选人要被删掉
        if (candidates[i].eliminated)
        {
            // 把投该候选人票为第一的选民的第一置-1，把0，1挪给原来的第二第三
            for (int j = 0; j < voter_count; j++)
            {
                if (preferences[j][i] == 0)
                {
                    preferences[j][i] = -1;
                    for (int k = 0; k < candidate_count; k++)
                    {
                        if (preferences[j][k] == 1)
                            preferences[j][k] = 0;
                    }
                    for (int k = 0; k < candidate_count; k++)
                    {
                        if (preferences[j][k] == 2)
                            preferences[j][k] = 1;
                    }
                }
            }
            // 删掉该候选人，数组后面元素往前挪
            for (int j = i ;j < (candidate_count - 1); j++)
            {
                candidates[j].name = candidates[j + 1].name;
                candidates[j].votes = candidates[j + 1].votes;
                candidates[j].eliminated = candidates[j + 1].eliminated;
            }
            candidate_count--;
            i--;
        }
    }
    return;
}
```

check50的时候一大堆报错。
```shell
:) runoff.c exists
:) runoff compiles
:) vote returns true when given name of candidate
:) vote returns false when given name of invalid candidate
:( vote correctly sets first preference for first voter
    vote function did not correctly set preferences
:) vote correctly sets third preference for second voter
:) vote correctly sets all preferences for voter
:( tabulate counts votes when all candidates remain in election
    tabulate function did not produce correct vote totals
:( tabulate counts votes when one candidate is eliminated
    tabulate function did not produce correct vote totals
:( tabulate counts votes when multiple candidates are eliminated
    tabulate function did not produce correct vote totals
:( tabulate handles multiple rounds of preferences
    tabulate function did not produce correct vote totals
:) print_winner prints name when someone has a majority
:) print_winner returns true when someone has a majority
:) print_winner returns false when nobody has a majority
:) print_winner returns false when leader has exactly 50% of vote
:) find_min returns minimum number of votes for candidate
:) find_min returns minimum when all candidates are tied
:( find_min ignores eliminated candidates
    find_min did not identify correct minimum
:) is_tie returns true when election is tied
:) is_tie returns false when election is not tied
:) is_tie returns false when only some of the candidates are tied
:( is_tie detects tie after some candidates have been eliminated
    is_tie did not return true
:( eliminate eliminates candidate in last place
    eliminate did not eliminate correct candidates
:( eliminate eliminates multiple candidates in tie for last
    eliminate did not eliminate correct candidates
:( eliminate eliminates candidates after some already eliminated
    eliminate did not eliminate correct candidates我没看出来我的代码哪里错了，应该都是对的啊
```
# 修改
这道 CS50 的 Runoff 题目是很多人的噩梦，因为它对数据结构的理解要求非常高。

你的代码之所以通过不了 check50，并不是因为语法错误，而是因为你对 preferences 数组的定义理解反了，以及你在 eliminate 函数中采用了“物理删除”的方法，这破坏了数组的索引对应关系。

以下是主要的三个逻辑错误和修改建议：

错误一：preferences 数组的含义理解反了
这是最关键的错误，直接导致了后面所有逻辑崩盘。

CS50 的定义：preferences[i][j] 应该存储的是 第 i 个选民的第 j 顺位候选人的索引 (index)。

你的代码：你把它存成了 preferences[i][candidate_index] = rank（第 i 个选民给某候选人投了第几名）。

修改 vote 函数：

```C
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // 错误写法: preferences[voter][i] = rank;
            // 正确写法: 记录第 voter 个选民，第 rank 名是候选人 i
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}
```
错误二：tabulate 统计票数的逻辑不对
由于 preferences 定义修正了，tabulate 的逻辑也要变。

你的逻辑：只看谁排第一（rank 0）。如果第一名被淘汰了，你的代码就没有给该选民算票。

正确逻辑：这就是 Runoff（即时决选）的核心。对于每一个选民，你需要看他的第一选择（rank 0）。如果这个人已经被淘汰 (eliminated == true)，你就得看他的第二选择（rank 1），以此类推，直到找到一个还在场的候选人，给那个候选人加票，然后处理下一个选民。

修改 tabulate 函数：
```C
void tabulate(void)
{
    // 遍历每一个选民
    for (int i = 0; i < voter_count; i++)
    {
        // 遍历该选民的偏好列表 (从 rank 0 到 rank N)
        for (int j = 0; j < candidate_count; j++)
        {
            // 获取该顺位对应的候选人索引
            int candidate_index = preferences[i][j];

            // 如果该候选人没有被淘汰
            if (!candidates[candidate_index].eliminated)
            {
                // 给他加一票
                candidates[candidate_index].votes++;
                // 该选民的票已经投出去了，跳出内层循环，处理下一个选民
                break;
            }
            // 如果被淘汰了，循环继续，查看 j+1 顺位
        }
    }
    return;
}
```
错误三：eliminate 不应该“物理删除”数组元素
你在 eliminate 函数中做了非常复杂的操作：把数组里的元素往前挪，把 candidate_count 减 1，甚至去修改 preferences 里的值。

为什么这是错的：preferences 数组里存的是候选人的索引（下标）。比如 preferences 记录了 index 3 是 Alice。如果你把数组里 index 2 的人删了，原本在 3 的 Alice 挪到了 2，但是 preferences 数组里还写着 3。这时候 3 可能变成了 Bob，或者越界了。整个数据全部乱套。

正确做法：CS50 的设计是静态数组。你只需要把 candidates[i].eliminated 设为 true 即可。不要移动数组，不要修改 candidate_count，不要修改 preferences。tabulate 函数会自动跳过被标记为 eliminated 的人。

修改 eliminate 函数：

```C
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // 如果该候选人票数等于最小值，且还没被淘汰
        if (candidates[i].votes == min && !candidates[i].eliminated)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
```
其他小错误的修正
find_min：必须忽略已淘汰的候选人。

```C
int find_min(void)
{
    int min_votes = voter_count; // 先设为一个最大可能值
    for (int i = 0; i < candidate_count; i++)
    {
        // 只有未淘汰的人才参与比较
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}
```
is_tie：这个函数是只读的 (read-only)。你现在的代码在 is_tie 里面把人淘汰了 (candidates[i].eliminated = true)，这是违规操作。淘汰动作只能在 eliminate 函数里做。

is_tie 的逻辑应该是：计算在场（未淘汰）的候选人中，是否所有人的票数都等于 min。如果有一个在场的人票数不等于 min，那就不是平局。

```C
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            // 只要有一个没被淘汰的人票数不等于 min，说明不是所有人平局
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    return true;
}
```
总结下一步
你需要完全重写 vote, tabulate, eliminate 这三个核心函数，去掉那些复杂的移动数组的逻辑，回归到最简单的“标记状态”逻辑。修改完这些后，你的代码就会变得非常简洁，并且能通过测试。
## Round2
```C
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
        if (temp > candidates[i].votes)
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
    int temp;
    for (int j = 0; j < voter_count; j++)
    {
        temp = 0;
        // 如果该选民投的候选人第一名已经删掉的话，preferences数组对应行整体往前移动一位
        while (candidates[preferences[j][temp]].eliminated)
        {
            temp++;
            preferences[j][0] = preferences[j][temp];
        }
    }
    return;
}
```
```shell
:) runoff.c exists
:) runoff compiles
:) vote returns true when given name of candidate
:) vote returns false when given name of invalid candidate
:) vote correctly sets first preference for first voter
:) vote correctly sets third preference for second voter
:) vote correctly sets all preferences for voter
:) tabulate counts votes when all candidates remain in election
:) tabulate counts votes when one candidate is eliminated
:( tabulate counts votes when multiple candidates are eliminated
    tabulate function did not produce correct vote totals
:( tabulate handles multiple rounds of preferences
    tabulate function did not produce correct vote totals
:) print_winner prints name when someone has a majority
:) print_winner returns true when someone has a majority
:) print_winner returns false when nobody has a majority
:) print_winner returns false when leader has exactly 50% of vote
:) find_min returns minimum number of votes for candidate
:) find_min returns minimum when all candidates are tied
:( find_min ignores eliminated candidates
    find_min did not identify correct minimum
:) is_tie returns true when election is tied
:) is_tie returns false when election is not tied
:) is_tie returns false when only some of the candidates are tied
:) is_tie detects tie after some candidates have been eliminated
:) eliminate eliminates candidate in last place
:( eliminate eliminates multiple candidates in tie for last
    eliminate did not eliminate correct candidates
:( eliminate eliminates candidates after some already eliminated
    eliminate did not eliminate correct candidates
```
# 修改
你已经取得了很大的进步！vote 和 is_tie 现在逻辑是对的，方向完全正确。

你现在的报错主要集中在 tabulate（计票）、find_min（找最少票）和 eliminate（淘汰）。

核心问题在于：你试图通过修改 preferences 数组来“移除”候选人，而不是在读取时“跳过”他们。
# 总结
谨慎破坏全局数组原来的物理结构，谨慎改变全局变量的大小
```C
// Numbers of voters and candidates
int voter_count;
int candidate_count;
```
这个不要乱改

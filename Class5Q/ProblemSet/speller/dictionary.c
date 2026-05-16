// Implements a dictionary's functionality
// 一切指针记得必要情况下置NULL
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    // 构造：末尾是'\0'，符合字符串要求
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int number = hash(word);
    node *ptr = table[number];
    while (ptr != NULL)
    {
        if(strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char c;
    char nowChar = 'a';
    // 下一个是新单词
    bool isNext = 1;
    // 下一个是新字母
    int isAlpha = 0;
    int wordNumber = 0;
    int tableNumber = 0;
    node *ptr;

    while (fread(&c, 1, 1, file))
    {
        if (isNext)
        {
            // 当前单词数组下标为0
            wordNumber = 0;
            // 确认一下table下标要不要变
            tableNumber += c - nowChar;
            // 确认一下首字母要不要变
            isAlpha = c - nowChar;
            // 是第一个字母或首字母变了的处理: ptr换到新字母行的头节点, nowChar变成当前c
            if (isAlpha || (c == 'a' && nowChar == 'a'))
            {
                ptr = malloc(sizeof(node));
                if (ptr == NULL)
                {
                    return false;
                }
                // 必要的防悬空
                ptr->next = NULL;
                table[tableNumber] = ptr;
                nowChar = c;
            }
            // 首字母没变,是下一个单词
            else
            {
                ptr->next = malloc(sizeof(node));
                if (ptr->next == NULL)
                {
                    return false;
                }
                ptr = ptr->next;
                // 必要的防悬空
                ptr->next = NULL;
            }
            ptr->word[wordNumber] = c;
            wordNumber++;
            isNext = 0;
        }

        // 还在当前单词内
        else
        {
            // 当前单词结束了
            if (c == '\n')
            {
                isNext = 1;
                ptr->word[wordNumber] = '\0';
            }
            // 当前单词没结束,还有可见内容物要存
            else
            {
                ptr->word[wordNumber] = c;
                wordNumber++;
            }
        }
    }

    // dic最后一行没有换行符号的话,要补一个'\0'
    if(!isNext)
    {
        ptr->word[wordNumber] = '\0';
    }

    // 完全忘记了,记得关文件夹
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int number = 0;
    node *ptr;
    for (int i = 0; i < N; i++)
    {
        ptr = table[i];
        while (ptr != NULL)
        {
            ptr = ptr->next;
            number++;
        }
    }
    return number;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *ptr;
    node *next;
    for (int i = 0; i < N; i++)
    {
        ptr = table[i];
        while (ptr != NULL)
        {
            if (ptr->next == NULL)
            {
                free(ptr);
                break;
            }
            else
            {
                next = ptr->next;
                free(ptr);
                ptr = next;
            }
        }
        // 销毁悬空指针
        // 但好像是没必要,但也可以有
        // table[i] = NULL;
    }

    return true;
}

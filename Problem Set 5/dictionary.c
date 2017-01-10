/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
unsigned int sze = 0;

typedef struct node
{
    struct node *children[27];
    bool is_word;
     
}node;

node* root;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* s)
{
    // TODO
   
    node *ptr = root;
    int n = strlen(s),i=0;
    while(i<n)
    {
        int a;
        if(isalpha(s[i]))
        {
            char p = tolower(s[i]);
            a = p - 'a';
        }
        
        else
        a = 26;
        if(ptr->children[a] == NULL)
            return false;
        else
        ptr = ptr->children[a];i++;
    }
    if(ptr->is_word == 1)
        return true;
 return false;   
    
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
void nulle(node *ptr)
 {
    ptr->children[0] = NULL;ptr->children[1] = NULL;ptr->children[2] = NULL;ptr->children[3] = NULL;ptr->children[4] = NULL;
    ptr->children[5] = NULL;ptr->children[6] = NULL;ptr->children[7] = NULL;ptr->children[8] = NULL;ptr->children[9] = NULL;
    ptr->children[10] = NULL;ptr->children[11] = NULL;ptr->children[12] = NULL;ptr->children[13] = NULL;ptr->children[14] = NULL;
    ptr->children[15] = NULL;ptr->children[16] = NULL;ptr->children[17] = NULL;ptr->children[18] = NULL;ptr->children[19] = NULL;
    ptr->children[20] = NULL;ptr->children[21] = NULL;ptr->children[22] = NULL;ptr->children[23] = NULL;ptr->children[24] = NULL;
    ptr->children[25] = NULL;ptr->children[26] = NULL;ptr->is_word = false;
 }
bool load(const char* dictionary)
{
FILE *dic = fopen(dictionary,"r");
    // TODO
    int c;
    
    node *add = malloc(sizeof(node));nulle(add);
            root = add;
    do
    {
                    int a;
        node *ptr = root;
        c = fgetc(dic);
        while(c !='\n' && c != EOF)
        {   
            if(!islower(c))
            a = 26;
            else
            a = c-'a';
            if(ptr->children[a] == NULL)
            {
              node *add = malloc(sizeof(node));nulle(add);
                ptr->children[a] = add;
            }
            ptr = ptr->children[a];
            c = fgetc(dic);
        }   
        ptr->is_word = 1;
        sze++;
    }while(c != EOF);
   return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return sze-1;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
void recunloder(node *ptr)
{
    for(int i = 0; i < 27; i++)
    {
        if(ptr->children[i] != NULL)
        recunloder(ptr->children[i]);
    }
    free(ptr);
}
bool unload(void)
{
    recunloder(root);
    return true;
}

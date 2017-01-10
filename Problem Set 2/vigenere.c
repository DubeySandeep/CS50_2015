/**
 *vigenere.c
 *
 *S.D.Feels
 *sdjaihobaba@gmail.com 
 *
 *rotating characters by a key word...:)
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("<keyword>/n");
        return 1;
    }
    string k = argv[1];
    int l = strlen(k), b = 0;
    for (int j = 0;j < l ;j++)
    {
        if (isdigit(k[j]))
        {
            printf ("<wrong keyword>\n");
            return 1;
        }
    }
    string s = GetString();
    for (int i = 0, n = strlen(s);i < n;i++)
    {
        if (isalpha(s[i]))
        {
              
            if (isupper(s[i]))
            {
                char c = (s[i] + toupper(k[b % l]) - 2 * 'A') % 26 + 'A'; 
                printf ("%c", c);  
            }
            else if (islower(s[i]))
            {
                printf ("%c", (s[i] + tolower(k[b % l]) - 2 * 'a') % 26 + 'a');  
            }   
            b++;
             
        }
        else
            printf ("%c", s[i]); 
    } 
    printf ("\n");
}    


   

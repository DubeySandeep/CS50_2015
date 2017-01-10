/**
 *caesar.c
 *
 *S.D.Feels
 *sdjaihobaba@gmail.com 
 *
 *rotating characters by a key ...:)
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
        printf ("not possible\n");
        return 1;
    }
    int key = atoi(argv[1]);       
    string text = GetString();
    for (int i = 0, n = strlen(text);i < n;i++)
    {
        if (isupper(text[i]))
        {
            printf ("%c", (text[i] - 'A' + key) % 26 + 'A');  
        }
        else if(islower(text[i]))
        {
            printf ("%c", (text[i] - 'a' + key) % 26 + 'a');  
        }
        else
            printf ("%c", text[i]);  
    }
    printf ("\n");
    return 0;
}
     


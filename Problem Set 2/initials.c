/**
 *initials.c
 * 
 *Sandeep Dubey
 *sdjaihobaba@gmail.com    
 *
 *says initial letters of name in uppercase :)
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    string name = GetString();
    if ( name != NULL)
    {
        // prints 1st letter in upper case
        printf ("%c", toupper(name[0]));
        for (int i=0, n=strlen(name);i < n;i++)
        {   
            // checking for spaces
            if (name[i] == ' ')
            {
                // prints all other intial letters in uppercase
                printf ("%c", toupper(name[i + 1]));
            }
        }
    }
    printf ("\n");
}

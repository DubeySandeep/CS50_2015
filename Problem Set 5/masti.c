#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
typedef struct node 
{
    struct node *chr[27];
    int n;
}
node;
node *root = NULL;
int load(const char* dictionary);
int check(char*s);
int main()
{
    
    int n = 0;string s =  malloc(sizeof(char)*50);
    printf("File name :-");
    scanf("%s",s);
         load(s);
        printf("%s\n",s);
    while(n != 1)
    {
        printf("1 = quit 2 = check\n");
        scanf("%d",&n);
        if(n == 1)
        {
                return 0;
        }    
            if(n == 2)
            {
                printf("Word:- ");
                scanf("%s",s);
                if(check(s) == 0)
                    printf("\n\t\t\tIt's in!!\n\n");
                else
                    printf("\n\t\t\tNope!!\n\n");
            }
       
       }
   return 0;
}
int load(const char* dictionary)
{
    // TODO
    int c;
    FILE *dic = fopen(dictionary,"r");
    node *add = malloc(sizeof(node));
            root = add;
            add->n = 0;
            node *ptr;
    do
    {
        ptr = root;
        for (c = fgetc(dic); c != '\n' && c != EOF; c = fgetc(dic))
        {   
            int a = c-'a';
            if(a > 26)
            a = 26;
            if(ptr->chr[a] != NULL)
            {
              ptr = ptr->chr[a];
            }
            else
            {
                node *add = malloc(sizeof(node));
                add->n = 0;
                ptr->chr[a] = add;
                ptr = add;
            }
        }   
        ptr->n = 1;
        
    }while(c != EOF);
   return 0;
}
int check(char*s)
{
    node *ptr = root;
    int n = strlen(s),i;
    for(i=0;i<n;i++)
    {
        int a = s[i]-'a';
        if(a > 27 || a < 0)
        a = 27;
        if(ptr->chr[a] == NULL)
            return 1;
        else
        ptr = ptr->chr[a];
    }
    if(ptr->n != 1)
        return 1;   
 return 0;   
}

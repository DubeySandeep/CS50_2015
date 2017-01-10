#include <stdio.h>
#include <cs50.h>
int main(void)
{

int height;
 do      
 { 
      printf("height: ");
       
      height = GetInt();
 }
 while (height < 0 || height >23);
       
 for(int a = 1; a <= height ; a++) // height of the blocks
 {
      for (int c = 1; c <=height - a ; c++) // number of spaces in each column
      {      
           printf (" ");
      }
      for(int b = 0 ; b <= a; b++) // number of blocks(#) in column
      {
           printf("#");             
      }
      printf("\n");
 }
}           


 

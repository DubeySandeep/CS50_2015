/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
 #include <stdlib.h>
#include <string.h>
#include <stdint.h>
int main(void)
{
    int i = 0;
    int j=0;
    char name[8];
    
    // intal part oj jpg image.
    uint8_t a[] = {0xff,0xd8,0xff,0xe0};
    uint8_t b[] = {0xff,0xd8,0xff,0xe1};
    // open card.raw.
    FILE* file = fopen("card.raw","r");
    FILE* img;
    // santay check for file.
    if (file != NULL)
    {
      uint8_t r[512];
      
       while( fread(r,512,1,file)==1)
       {
            // comparing .
            if(memcmp(r,a,4)==0 || memcmp(r,b,4)==0)
            {
                if(j>0)
                {
                    fclose(img);
                }
                sprintf(name,"%03d.jpg",j);
                img = fopen(name,"w");
               
                j++;
                i = 1 ;
                
            }
            // copying into .jpg file.
            if(i == 1)
            {
               fwrite(r,512,1,img);
            }
       }
       
    }         
       
   
    
}



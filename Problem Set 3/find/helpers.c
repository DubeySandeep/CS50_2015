/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // equating upper and lower limit
    int upper = n - 1;
    int lower = 0;
    // searching loop
    while(lower <= upper)
    {
        // abstracting the middle no.
        int middle = (lower + upper) / 2;
        // cheching for the middle of array
        if ( values[middle] > value)
        {
            upper = middle - 1;               
        }
        else if (values[middle] < value)
        {
            lower = middle + 1;
        }
        else if (values[middle] == value)
        {
            return true;    
        }    
    }
    return false;                               
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    if (n >= 1)
    {
        for (int k = 0;k < n;k++)
        {
            int min = k;
            for (int j = k + 1;j < n;j++)
            {
                if (values[j] < values[min])
                {
                    int temp = values[min];
                    values[min] = values[j];
                    values[j] = temp; 
                }
            }       
        }  
   }
}

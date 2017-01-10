#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
printf ("O hai!");
float x;
do{
printf ("How much change is owed ?");
x= GetFloat();
}
while (x<0);
x =x*100;
int n = round(x);
int Q = n/25; //no. of quater
int b = n%25;
int D = b/10; //no. of dimes
int d = b%10;
int N = d/5; //no. of nickles
int P = d%5; //no. of pennies

printf ("%d\n",Q+D+N+P);
}

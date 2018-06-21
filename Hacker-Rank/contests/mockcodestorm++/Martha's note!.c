/*
https://www.hackerrank.com/contests/mockcodestorm++/challenges/marthas-note/problem

*/

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
   char c;
   while((c=getchar())!=EOF)
   {
     if(isalpha(c))
     {
       if(isupper(c))
       {
         k=c-'A';
         k+=2;
         k%=26;
         c=k+'A';
       }
       else
       {
         k=c-'a';
         k+=2;
         k%=26;
         c=k+'a';
       }
     }
     putchar(c);
   }
}

/*
https://www.hackerrank.com/contests/codestorm-1-1/challenges/palindrome-maker/problem
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ispallindrome(char *s,int len)
{
    int i=0;
    while(i<=len)
    {
        if(s[i]!=s[len]) return 0;
        i++;
        len--;
    }
    return 1;
}

int main() {

    char ch,s[150],temp,temp1;
    int len,i=0,j;
    scanf("%s",s);
    for(i=0;s[i]!=0;i++) ;
    j=len=i-1;
    i=0;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            temp=s[i];
            temp1=s[j];
            while(i<len)
            {
                s[i]=s[i+1];
                i++;
            }
            s[len]=0;
            if(ispallindrome(s,len))
            {
                putchar(temp);
                return 0;
            }
            else
            {
                putchar(temp1);
                return 0;
            }
        }
        i++;
        j--;
    }
    return 0;
}

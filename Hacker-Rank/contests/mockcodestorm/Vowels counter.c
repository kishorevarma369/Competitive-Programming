/*
https://www.hackerrank.com/contests/mockcodestorm/challenges/vowels-counter
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int count=0;
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(ch=='A'||ch=='a') count++;
        else if(ch=='E'||ch=='e') count++;
        else if(ch=='I'||ch=='i') count++;
        else if(ch=='O'||ch=='o') count++;
        else if(ch=='U'||ch=='u') count++;
    }
    printf("%d\n",count);
    return 0;
}

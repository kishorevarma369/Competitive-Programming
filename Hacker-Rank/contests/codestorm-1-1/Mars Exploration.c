/*
Mars Exploration

https://www.hackerrank.com/contests/codestorm-1-1/challenges/mars-exploration
*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int marsExploration(char* s)
{
    int i=0,j=0,count=0;
    char s1[]="SOS";
    while(s[i]!=0)
    {
        if(s[i]!=s1[j])
        {
            count++;
        }
        i++;
        j++;
        if(j==3) j=0;
    }
    return count;
}

int main() {
    char* s = (char *)malloc(150 * sizeof(char));
    scanf("%s", s);
    int result = marsExploration(s);
    printf("%d\n", result);
    return 0;
}

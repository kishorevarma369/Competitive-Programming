/*
https://www.hackerrank.com/contests/mockcodestorm/challenges/consecutive-numbers-2/problem
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,i,j,tmp,flag=0,count=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    for(i=0;i<n-1;i++)
    {
        if((a[i]==(a[i+1]-1)))
        {
           for(;i<n-1;i++)
            {
                if((a[i]==(a[i+1]-1)))
                {
                    count++;
                }
                else goto k;
            }
            k:
            count++;
        }
    }
    printf("%d",count);
    return 0;
}

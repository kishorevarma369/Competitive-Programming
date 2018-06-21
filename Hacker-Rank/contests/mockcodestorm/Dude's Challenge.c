/*
https://www.hackerrank.com/contests/mockcodestorm/challenges/dudes-challenge/problem
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0) break;
    }
    if(i==(n/2+1)) printf("PRIME");
    else printf("NON PRIME");
    return 0;
}

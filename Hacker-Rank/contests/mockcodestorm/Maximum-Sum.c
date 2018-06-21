/*
https://www.hackerrank.com/contests/mockcodestorm/challenges/max-sum-3
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n1,n2,min=-1000,max=-1,b,i;
    scanf("%d %d",&n1,&n2);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&b);
        if(b>max) max=b;
    }
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b);
        if(b>min) min=b;
    }
    printf("%d\n",max+min);
        return 0;
}

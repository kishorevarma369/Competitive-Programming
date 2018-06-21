/*

      Question :-

          https://www.hackerrank.com/challenges/mini-max-sum

      ***************************************************************************
      --------------------written by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

#include <stdio.h>

#define n 5
int main()
{
    unsigned long long int arr[n],min,max,temp;
    int i=0,j=0;
    for(i=0;i<n;i++) scanf("%llu",arr+i);
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=i+1;j%n!=i;j++) temp+=arr[j%n];
        if(i==0)
        {
            min=temp;
            max=temp;
        }
        if(temp<min) min=temp;
        if(temp>max) max=temp;
    }
    printf("%llu %llu",min,max);
    return 0;
}

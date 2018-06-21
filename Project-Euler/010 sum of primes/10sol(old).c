#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//give k value here to get all 10001 primes
#define k 2000000
#define l 500000
int main()
{
    int n,num,i,j=0,prime;
    int *a=(int *)malloc(sizeof(int)*l);
    unsigned long long int sum=0;
    a[j++]=2;
    sum+=2;
    for(n=3;n<k;n++)
    {
        prime=1;
        for(i=0;a[i]<=sqrt(n);i++)
        {
            if(n%a[i]==0){
                prime=0;
                break;
            }
        }
        if(prime==1){
          sum+=n;
          a[j++]=n;
        }
    }
    printf("sum is %llu \n",sum);
    free(a);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define uplim 100001
int prime[uplim],prime_count;
int l,r;
void gen_prime()
{
    prime[0]=2;
    prime_count++;
    int isprime;
    for(int i=3;prime_count<uplim;i+=2)
    {
        isprime=1;
        for(int j=0;j<prime_count&&prime[j]*prime[j]<=i;j++)
        {
            if(i%prime[j]==0){ isprime=0;break;}
        }
        if(isprime) prime[prime_count++]=i;
    }
}

int cmp(const void *a,const void *b)
{
    return (*(int*)a)-(*(int*)b);
}

int binarySearch(int arr[],int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
        if (arr[m] == x) 
            return 1; 
        if (arr[m] < x) 
            l = m + 1;  
        else
            r = m - 1; 
    } 
    return 0; 
} 

int bs(int *b,int n,int val)
{
    l=0;
    r=n-1;
    int tval=val*2;
    while(l<=r)
    {
        if(binarySearch(b,tval)) return tval;
        tval+=val;
    }
    return 0;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    gen_prime();
    int n;
    scanf("%d",&n);
    int a[n],b[n],flag,j;
    for(int i=0;i<n;i++) scanf("%d",a+i),b[i]=a[i];
    qsort(b,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
    {
        flag=bs(b,n,a[i]);
        if(flag&&flag<uplim) printf("%d ",prime[flag-1]);
        else printf("0 ");
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
int LIS(int *a,int n)
{
    
}
int main()
{
    int n,a[50],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    j=LIS(a,n);
    printf("%d",j);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

#define mymod 1000000007
#define lim 100001
int n,val,a[lim];

int calc(int i,int j)
{
    if(i==n||j-1>i) return 0;
    if(a[i]%j==0) return 1+calc(i+1,j+1)+calc(i+1,j);
    return calc(i+1,j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int sf[n+2];
    for(int i=0;i<=n+1;i++) sf[i]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n;j>=1;j--) 
    }
    cout<<calc(0,1);
    return 0;
}
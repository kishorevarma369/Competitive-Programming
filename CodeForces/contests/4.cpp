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
    cout<<calc(0,1);
    return 0;
}
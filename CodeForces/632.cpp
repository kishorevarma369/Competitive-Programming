#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    ll n,t,i;
    vector<ll> op;
    cin>>n;
    ll ans;
    bool flag=false;
    while(1)
    {
         t=n;
         i=1;
         if(n&1)
         {
              while(n&i) i<<=1;

         }
         ans=i;
         while(i<=n&&(n&i)==0) i<<=1;
          n=n^((ans/i)-1);
          op.push_back(ans);
         if(n!=0&&(n&(n-1))==0) break;
          n=n+1;
         if(n!=0&&(n&(n-1))==0) break;
    }
    return 0;
}
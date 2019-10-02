#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    ll m,n,val;
    ll a1o=0,a1e=0,a2o=0,a2e=0;
    cin>>m>>n;
    for(int i=0;i<m;i++){
         cin>>val;
         if(val&1) a1o++;
         else a1e++;
    }
    for(int i=0;i<n;i++){
         cin>>val;
         if(val&1) a2o++;
         else a2e++;
    }
    cout<<(min(a1o,a2e)+min(a2o,a1e))<<'\n';
    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(int argc, char const *argv[])
{
  ll t;  
  cin>>t;
  while(t--)
  {
    ll n,k,val;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) {
        cin>>v[i];
        v[i]=k/v[i];
    }
    for(ll i=0;i<n;i++){
        cin>>val;
        v[i]*=val;
    }
    sort(v.begin(),v.end(),greater<ll>());
    cout<<v[0]<<'\n';
  }
  return 0;
}

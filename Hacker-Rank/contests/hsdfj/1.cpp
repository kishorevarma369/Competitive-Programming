#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,h;
    cin>>n>>h;
    vector<int> v(n),l(n);
    for(auto &i:v) cin>>i;
    for(auto &i:l) cin>>i;
    int ans=0,t;
    for(int i=0;i<l.size();i++)
    {
        t=ceil(v[i]-(float(l[i])/4))-h;
        ans=max(ans,t);
    }
    cout<<ans<<'\n';
    return 0;
}
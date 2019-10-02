#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> l;
    int val;
    for(int i=0;i<4;i++) cin>>val,l.push_back(val);
    int n;
    cin>>n;
    vector<bool> v(n+1,0);
    for(auto &val:l)
    {
        for(int i=0;i<=n;i+=val) v[i]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(v[i]) ans++;
    cout<<ans<<'\n';
    return 0;
}
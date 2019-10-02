#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    priority_queue<int,vector<int>,greater<int>> v;
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++) cin>>val,v.push(val);
    int ans=0;
    // while(v.size()>1)
    // {
    //     val=v.top();v.pop();
    //     val+=v.top();v.pop();
    //     v.push(val);
    //     ans+=val;
    // }
    // cout<<ans<<'\n';
    for(auto &value:v) cout<<value<<'\n';
    return 0;
}
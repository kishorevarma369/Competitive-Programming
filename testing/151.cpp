#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

void solve()
{
    ll n,k,val;
    cin>>n>>k;
    map<ll,ll> m;
    for(int i=0;i<n;i++){
        cin>>val;
        while((val%k)==0) val/=k;
        m[val]++;
    }
    if(m.size()<=1)
    {
        cout<<"0\n";
        return;
    }
    ll prev=m.rbegin()->first-m.begin()->first;
    while(m.size()>1)
    {
        auto pr=*m.begin();
        if(pr.second==1)
        {
            auto tmp=pr.first;
            m.erase(m.begin());
            m[tmp*k]++;
        }
        else{
            m.begin()->second--;
            auto tmp=pr.first;
            m[tmp*k]++;
        }
        auto new_res=m.rbegin()->first-m.begin()->first;
        if(new_res<=prev)
        {
            prev=new_res;
        }
        else break;
    }
    cout<<prev<<'\n';
}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}


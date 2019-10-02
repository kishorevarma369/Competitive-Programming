#include<bits/stdc++.h>

using namespace std;

#define uplim 100005
#define mod 1000000007
#define multiply(val1,val2) (((val1%mod)*(val2%mod))%mod)
#define add(val1,val2) ((val1%mod+val2%mod)%mod)
#define substract(val1,val2) (((val1%mod)-(val2%mod)+mod)%mod)

typedef long long int ll;

void solve()
{
    int n,q,l,r;
    cin>>n>>q;
    string s;
    cin>>s;
    map<char,vector<int>> v;
    for(int i=0;i<n;i++)
    {
        v[s[i]].push_back(i);
    }
    bool found;
    while(q--)
    {
        found=false;
        cin>>l>>r;
        l--,r--;
        if(r-l<2){
            cout<<"NO\n";continue;
        }
        for(auto &pr:v)
        {
            auto &mp=pr.second;
            auto x=lower_bound(mp.begin(),mp.end(),l)-mp.begin();
            auto y=upper_bound(mp.begin(),mp.end(),r)-mp.begin();
            y--;
            while(x<y&&y-x>2)
            {
                if(y-x+1>(mp[y]-mp[x]+1)/2)
                {
                    if(mp[x]>=l&&mp[y]<=r){
                        found=true;
                        break;
                    }
                }
                if(mp[y]-mp[y-1]<mp[x+1]-mp[x]) x++;
                else y--;
                //y--
            }            
            if(found) break;
        }
        if(found) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
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
            auto it2=upper_bound(mp.begin(),mp.end(),r);
            auto it1=lower_bound(mp.begin(),mp.end(),l);
            // auto x=(int)(it2-it1);
            // it2--;
            
            // it2--;
            if(it1!=mp.end()&&*it1<=r)
            {
                it2--;
                int beg=*it1;
                while(it2-it1>0&&(*it2-beg+1)>2)
                {
                    if(it2-it1+1>(*it2-beg+1)/2)
                    {
                        if(*it1>=l&&*it2<=r){
                            found=true;
                            break;
                        }
                    }
                    it2--;
                }
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
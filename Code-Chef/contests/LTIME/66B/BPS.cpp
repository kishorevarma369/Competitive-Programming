#include<bits/stdc++.h>

using namespace std;

int fact[11];

void pre()
{
    fact[0]=1;
    for(int i=1;i<11;i++) fact[i]=i*fact[i-1];
}

int main()
{
    int t;
    pre();
    cin>>t;
    while(t--)
    {
        int n,m,count=0,p,q,g;
        cin>>n>>m;
        vector<pair<int,int>> pairs;
        vector<int> v(n);
        for(auto &i:v) cin>>i;
        for(int i=0;i<m;i++)
        {
            pair<int,int> tmp;
            cin>>tmp.first>>tmp.second;
            if(tmp.first>tmp.second) swap(tmp.first,tmp.second);
            if(tmp.first!=tmp.second) pairs.push_back(tmp); 
        } 
        string s="012345678";
        m=pairs.size();
        s=s.substr(0,m);
        vector<int> finar=v;
        for(int i=0;i<m;i++)
        {
            reverse(finar.begin()+pairs[i].first-1,finar.begin()+pairs[i].second);
        }
        do
        {
            auto tmp=v;
            for(int i=0;i<m;i++)
            {
                reverse(tmp.begin()+pairs[s[i]-'0'].first-1,tmp.begin()+pairs[s[i]-'0'].second);
            }
            // for(auto &i:pairs)
            // {
            //     reverse(tmp.begin()+i.first-1,tmp.begin()+i.second);
            // }
            if(finar==tmp) count++;
        }
        while(next_permutation(s.begin(),s.end()));
        p=count;
        q=fact[m];
        g=__gcd(p,q);
        cout<<p/g<<'/'<<q/g<<'\n';
    }
    return 0;
}
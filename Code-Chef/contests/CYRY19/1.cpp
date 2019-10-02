#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        int ans=0;
        cin>>s;
        vector<pair<char,int>> m(26);
        for(int i=0;i<26;i++) m[i].first='a'+i,m[i].second=0;
        for(auto &i:s) m[i-'a'].second++;
        sort(m.begin(),m.end(),[](auto &p,auto &q){return p.second>q.second;});
        cout<<m[0].first-m[1].first<<'\n';
    }
    return 0;
}
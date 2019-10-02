#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        int rg[2]={0};
        string s;
        cin>>s;
        for(auto &i:s) if(i=='R') rg[0]++;else rg[1]++;
        if(rg[0]!=rg[1]){
            cout<<"no\n";
            continue;
        } 
        rg[0]=rg[1]=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1]) if(s[i]=='R') rg[0]++; else rg[1]++;
        }
        if(s[int(s.size())-1]==s[0]) if(s[0]=='R') rg[0]++; else rg[1]++;
        if(rg[0]==rg[1]&&rg[0]<=1) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}

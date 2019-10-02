#include<bits/stdc++.h>

using namespace std;
string s;
vector<bool> state;
int n,p,t;
vector<int> a;

void fun()
{
    for(int i=0;i<n;i++)
    {
        if(s[i]!='.') a[i]=s[i]-'0';
        else
        {
            t=(i+p)%n;
            if(s[t]=='.') a[i]=t;
            else if(s[t]=='1') a[i]=0,s[i]='0';
            else a[i]=1,s[i]='1';
            
        } 
    }
}

int main()
{
    int pos;
    cin>>n>>p;
    cin>>s;
    a.resize(n,0);
    state.resize(n);
    for(auto i:s) if(s[i]=='.') state[i]=true;
    bool flag=true;
    while(flag)
    {
        fun();
        flag=false;
        for(int i=0;i<n;i++) if(s[i]=='.') flag=true;
    }
    cout<<s<<'\n';
    for(auto &i:a) cout<<i<<' ';
    return 0;
}
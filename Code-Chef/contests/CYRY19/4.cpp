#include<bits/stdc++.h>

using namespace std;
string s;
vector<bool> state;
int n,p,t,tofillcount;
vector<int> a;
list<int> tofill;

void base_fun()
{
    int i;
    for(auto it=tofill.begin();it!=tofill.end();it++)
    {
        i=*it;
        if(s[i]=='.')
        {
            t=(i+p)%n;
            if(s[t]=='.') a[i]=t;
            else{
                if(s[t]=='1') s[i]='0';
                else s[i]='1';
                it=tofill.erase(it);
                it--;
            } 
        } 
    }
}

int main()
{
    int pos;
    cin>>n>>p;
    cin>>s;
    a.resize(n,-1);
    state.resize(n);
    for(int i=0;i<n;i++) if(s[i]=='.') state[i]=true,tofill.push_back(i);
    base_fun();
    cout<<s<<'\n';
    for(auto it=tofill.begin();it!=tofill.end();it++)
    {
        cout<<*it<<'-'<<a[*it]<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

void perform(string s)
{
    string c(s.size(),'0');
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='4')
        {
            s[i]='3';
            c[i]='1';
        }
    }
    cout<<s<<' ';
    for(int i=0;i<c.size();i++)
    {
        if(c[i]!='0')
        {
            for(;i<c.size();i++) cout<<c[i];
        }
    }
    cout<<'\n';
}

int main()
{
    int t;
    cin>>t;
    string s;
    for(int i=1;i<=t;i++)
    {
        cin>>s;
        cout<<"Case #"<<i<<": ";
        perform(s);
    }
    return 0;
}
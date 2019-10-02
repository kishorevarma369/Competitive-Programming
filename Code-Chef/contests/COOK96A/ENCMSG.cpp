#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll t,i;
    cin>>t;
    char a[26];
    for(i=0;i<26;i++) a[i]='a'+i;
    while(t--)
    {
        string s;
        int n;
        cin>>n;
        cin>>s;
        for(i=0;i+1<n;i+=2) swap(s[i],s[i+1]);
        for(i=0;i<n;i++) s[i]=a[25-(s[i]-'a')];
        cout<<s<<'\n';
    }
    
    return 0;
}
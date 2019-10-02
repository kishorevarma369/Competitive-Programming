#include<bits/stdc++.h>

using namespace std;
#define uplim 100003
#define mod 1000000007ll
typedef unsigned long long int ll;
int modinv[uplim],charset[uplim][26];
ll factorial[uplim],factinv[uplim];

string s;

ll mypower(ll x,ll y)
{
    if(y==0) return 1;
    ll p=mypower(x,y/2);
    p=(p*p)%mod;
    if(y&1) return (p*x)%mod;
    return p;
}

void pre()
{
    factinv[0]=1;
    modinv[0]=1;
    factinv[1]=1;
    modinv[1]=1;
    factorial[0]=1;
    factorial[1]=1;
    for(int i=2;i<uplim;i++){
        modinv[i]=mypower((ll)i,mod-2);
        factinv[i]=(factinv[i-1]*modinv[i])%mod;
        factorial[i]=(factorial[i-1]*i)%mod;
    }
    //processing the string
    for(int i=0;i<s.size();i++)
    {
        charset[i+1][s[i]-'a']++;
    }
    for(int i=2;i<=s.size();i++)
    {
        for(int j=0;j<26;j++)
        {
            charset[i][j]+=charset[i-1][j];
        }
    }
}

int main()
{
    int t,p,q,k;
    cin>>s>>t;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    pre();
    ll num,singlechar;
    ll ans=1,tans;
    while(t--)
    {
        cin>>p>>q;
        num=singlechar=0;
        ans=1;
        p--;
        for(int i=0;i<26;i++)
        {
            k=(charset[q][i]-charset[p][i]);
            singlechar+=k%2;
            k/=2;
            num+=k;
            ans=(ans*factinv[k])%mod;
        }
        if(singlechar) ans=(ans*singlechar)%mod;
        ans=(ans*factorial[num])%mod;
        cout<<ans<<'\n';
    }
}
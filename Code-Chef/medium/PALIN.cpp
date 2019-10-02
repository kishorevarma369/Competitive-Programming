#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007

#define fast_io() (cin.tie(NULL),ios_base::sync_with_stdio(false))

typedef unsigned long long int ull;
typedef long long int ll;


template<typename t>
t modulo_power(t x,t y,t mod=mymod)
{
    if(y<=0) return 1;
    if(y==1) return x;
    t z=modulo_power(x,y/2);
    if(y&1) return ((z*z)%mod*x)%mod;
    return (z*z)%mod;
}

void increment(string &str)
{
    int j=str.size();
    while(--j>=0)
    {
        if(str[j]!='9'){
            str[j]++;
            break;
        }
        else str[j]='0';
    }
    if(j<0) str="1"+str;
}

void solve()
{
    string str;
    cin>>str;
    if(str.size()==1) 
    {
        if(str[0]<'9') cout<<(++str[0])<<'\n';
        else cout<<"11\n";
        return;
    }
    int i,j;
    bool flag=true,performed=false;
    while(flag)
    {
        flag=false;
        performed=false;
        i=0,j=str.size()-1; 
        while(i<j)
        {
            if(str[i]>str[j])
            {
                str[j]=str[i];
                performed=true;
            }
            else if(str[i]<str[j]){
                str[j]=str[i];
                int k=j;
                performed=true;
                while(--k>=0)
                {
                    if(str[k]!='9')
                    {
                        str[k]++;
                        break;
                    }
                    else
                    {
                        str[k]='0';
                    }
                }
                if(k<=i)
                {
                    flag=true;
                    break;
                }
            }
            i++;
            j--;
        }
        if(!performed)
        {
            increment(str);
            flag=true;
        }
    }
    cout<<str<<'\n';
}

int main()
{
    fast_io();
    ull t;
    cin>>t;
    while(t--) solve();
    return 0;
}
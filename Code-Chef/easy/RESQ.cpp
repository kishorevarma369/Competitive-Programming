#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i=1,val,c=INT_MAX;
        cin>>n;
        while(i*i<=n)
        {
            if(n%i==0)
            {
                val=n/i;
                if(i!=val) val=abs(val-i);
                else val=0;
                if(val<c) c=val; 
            } 
            if(c==0) break;
            i++;
        }
        cout<<c<<'\n';
    }
    return 0;
}

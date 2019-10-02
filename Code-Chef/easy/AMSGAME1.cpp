#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main(int argc, char const *argv[])
{
    ll t,n,val,mygcd;
    cin>>t;
    while(t--)
    {
        cin>>n>>mygcd;
        for(int i=1;i<n;i++)
        {
            cin>>val;
            mygcd=__gcd(mygcd,val);
        } 
        cout<<mygcd<<'\n';
    }
    return 0;
}

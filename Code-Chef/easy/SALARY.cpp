#include<bits/stdc++.h>

using namespace std;

typedef int ll;

int main(int argc, char const *argv[])
{
    ll t,n,mymin,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        c=0;
        cin>>a[0];
        mymin=a[0];
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
            mymin=min(a[i],mymin);
        }
        for(int i=0;i<n;i++) c+=a[i]-mymin;
        cout<<c<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main(int argc, char const *argv[])
{
    ll n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        if(a==0||b==0)
        {
            if(a==0) cout<<"0 0\n";
            else cout<<"0 "<<a<<'\n';
            continue;
        }
        cout<<a/b<<' '<<a%b<<'\n';
    }
    return 0;
}

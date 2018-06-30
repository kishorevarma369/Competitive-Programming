#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ul;

int main(int argc, char const *argv[])
{
    ul n,a,b=0,k;
    cin>>n;
    k=n;
    while(k--)
    {
        cin>>a;
        b+=a;
    }
    k=(sqrt(1+8*b)-1)/2;
    if(k*(k+1)==2*b) cout<<"YES";
    else cout<<"NO";

    return 0;
}

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    n%=6;
    if(n==0||n==1||n==3||n==6) cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}

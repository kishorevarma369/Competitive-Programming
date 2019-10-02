#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int c=0;
    cin>>s;
    for(auto &i:s) if(i=='4'||i=='7') c++;
    if(c==4||c==7) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
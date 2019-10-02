#include<bits/stdc++.h>

using namespace std;

int main()
{
    int u=0,l=0;
    string s;
    cin>>s;
    for(auto &i:s) if(isupper(i)) u++;
    else l++;
    if(u>l) for(auto &i:s) i=toupper(i);
    else for(auto &i:s) i=tolower(i);
    cout<<s<<'\n';
    return 0;
}
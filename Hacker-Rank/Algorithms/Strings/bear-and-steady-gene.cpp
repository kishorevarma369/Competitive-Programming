#include <bits/stdc++.h>

using namespace std;
#define uplim 500005
string s;
int ms,n;
map<char,int> mymap;

bool isvalid()
{
    for(auto &node:mymap)
    {
        if(node.second>ms) return false;
    }
    return true;
}

int main()
{
    cin>>n>>s;
    ms=n/4;
    int i,fmax=0;
    for(i=0;i<n;i++)
    {
        mymap[s[i]]++;
        if(!isvalid())
        {
            mymap[s[i]]--;
            fmax=i-1;
            break;
        }
    }
    int mymin;
    if(i==n) mymin=0,fmax=n;
    else mymin=n-fmax-1;
    for(i=n-1;i>=0&&fmax>=0&&i>fmax;i--)
    {
        mymap[s[i]]++;
        while(!isvalid()&&fmax>=0)
        {
            mymap[s[fmax]]--;
            fmax--;
        }
        if(fmax<0&&!isvalid()) break;
        mymin=min(mymin,n-(fmax+1+n-i));
        // 0 1 2 3 4 5 6 7 
        // cout<<mymin<<'\n';
    }
    cout<<mymin<<'\n';
    return 0;
}
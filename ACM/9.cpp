#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    vector<pair<char,int>> v={{'c',2},{'o',1},{'d',1},{'f',1},{'e',2},{'h',1}};
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[26]={0};
        string s;
        for(int i=0;i<n;i++)
        {
             cin>>s;
             for(auto &ch:s) a[ch-'a']++;
        }
        int mymin=INT_MAX;
        for(auto &pr:v){
            int ch=pr.first-'a';
            // cout<<pr.first<<' '<<a[ch]<<' ';
            mymin=min(mymin,a[ch]/pr.second);
            // cout<<mymin<<' ';
        }
        // cout<<'\n';
        if(mymin==INT_MAX) cout<<"0\n";
        else cout<<mymin<<'\n';
    }
    return 0;
}
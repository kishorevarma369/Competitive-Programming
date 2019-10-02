#include<bits/stdc++.h>

using namespace std;
// time taken 5 minutes 47 seconds and 60 milli secondss
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &val:v) cin>>val;
    sort(v.begin(),v.end(),greater<int>());
    int i;
    for(i=1;i<v.size();i++)
    {
        if(v[i]!=v[0]) break;
    }
    if(i==v.size()) cout<<"0\n";
    else cout<<v[i]<<'\n';
    return 0;
}
#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int n1,n2,n3,a,i;
    cin>>n1>>n2>>n3;
    int n=n1+n2+n3;
    map<int,int> m;
    for(i=0;i<n;i++)
    {
        cin>>a;
        m[a]++;
    }
    vector<int> v;
    for(auto &i:m)
    {
        if(i.second>1) v.push_back(i.first);
    }
    m.clear();
    cout<<v.size()<<'\n';
    for(auto &i:v) cout<<i<<'\n';
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s,f;
    cin>>n>>s;
    f.push_back(s[0]);
    for(int i=1;i<n;i++)
    {
        if(s[i]!=f.back()) f.push_back(s[i]);
    }
    cout<<s.size()-f.size();
    return 0;
}
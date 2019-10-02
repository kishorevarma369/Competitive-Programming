#include<bits/stdc++.h>

using namespace std;

set<char> ans;
vector<string> v={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    for(auto &i:s) ans.insert(v[i-'0'][0]);
    auto l=s.size();
    for(unsigned int i=1;i<l;i++)
    {
        int p=s[i-1]-'0'-1, q=s[i]-'0';
        auto ch=v[q][p%(v[q].size())];
        ans.insert(ch);
    }
    cout<<ans.size();
    return 0;
}

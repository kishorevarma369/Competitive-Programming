#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

void perform()
{
    string s;
    cin>>s;
    vector<int> v;
    int val=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='.') val++;
        else
        {
            v.push_back(val);
            val=0;
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans^=v[i];
    }
    if(ans%3) cout<<"Yes\n";
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}

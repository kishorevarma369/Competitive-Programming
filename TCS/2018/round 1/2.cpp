#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void lrotate(string &s, int d)
{
    d=d%s.size();
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}
 
void rrotate(string &s, int d)
{
    d=d%s.size();
   lrotate(s, s.length()-d);
}

int main(int argc, char const *argv[])
{
    string s,s1,s2;
    cin>>s;
    s1=s;
    int t,n;
    char ch;
    cin>>t;
    while(t--)
    {
        cin>>ch;
        cin>>n;
        if(ch=='L') lrotate(s,n);
        else rrotate(s,n);
        s2.push_back(s[0]);
        //cout<<s<<'\n';
    }
    map<char,int> m1,m2;
    for(auto &i:s2) m1[i]++;
    unsigned i=0,d=s2.size();
    if(d>s1.size())
    {
        cout<<"NO";
        return 0;
    }
    for(i=0;i<d;i++) m2[s1[i]]++;
    for(;i<s1.size();i++)
    {
        m2[s1[i]]++;
        if(m2[s1[i-d]]==1)
        {
            m2.erase(m2.find(s1[i-d]));
        }
        else m2[s1[i-d]]--;
        if(m1==m2)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}

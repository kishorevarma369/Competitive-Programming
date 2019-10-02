#include<bits/stdc++.h>

using namespace std;

bool fun(string &str)
{
    int s=str.size();
    if(s<3) return false;
    for(int i=2;i<s;i++)
    {
        if(str[i-2]=='n'&&str[i-1]=='o'&&str[i]=='t')
        {
            if(i-3>=0&&str[i-3]!=' ') continue;
            if(i+1<s&&str[i+1]!=' ') continue;
            return true;
        }
    }
    return false;
}


int main()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        getline(cin,s);
        while(s.size()==0) getline(cin,s);
        if(fun(s)) cout<<"Real Fancy\n";
        else cout<<"regularly fancy\n";
    }
    return 0;
}
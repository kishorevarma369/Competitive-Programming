#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int l=(int)s.size();
    for(int i=0;i<l;i++)
    {
        if(s[i]=='.') cout<<'0';
        else
        {
            i++;
            if(s[i]=='.') cout<<'1';
            else cout<<'2';
        }
    }
    return 0;
}
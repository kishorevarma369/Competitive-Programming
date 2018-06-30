#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int n,i;
    cin>>n;
    while(n--)
    {
        int a,val=0,i=0;
        char s[300];
        cin>>a>>s;
        if(a==0)
        {
            cout<<s<<'\n';
            continue;
        }
        while(s[i])
        {
            val=(val*10+(int)(s[i]-'0'))%a;
            i++;
        }
        if(val==0)
        {
            cout<<a<<'\n';
            continue;
        }
        cout<<__gcd(a,val)<<'\n';
    }
    return 0;
}

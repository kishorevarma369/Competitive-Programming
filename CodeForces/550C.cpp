
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int l=s.size(),val;
    for(int i=0;i<l;i++)
    {
        for(int j=i+1;j<l;j++)
        {
            for(int k=j+1;k<l;k++)
            {
                val=(s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0';
                if(val%8==0) goto found;
            }
        }
    }
    cout<<"NO\n";
    return 0;
    found:
    cout<<"YES\n"<<val;
    return 0;
}

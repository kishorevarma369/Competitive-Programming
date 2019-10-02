#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        long long int c=0;
        cin>>s;
        for(auto &i:s)
        {
            if(i!='4'&&i!='7') c++;
        }
        cout<<c<<'\n';
    }
    return 0;
}

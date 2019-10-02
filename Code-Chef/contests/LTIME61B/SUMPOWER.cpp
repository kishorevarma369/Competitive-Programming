#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    long long int t,n,w,i,j,co;
    long long int p[100001];
    //god damn codechef -> int is 2bytes in their environiment
    cin>>t;
    while(t--)
    {
        string s;
        cin>>n>>w;
        cin>>s;
        co=0;
        for(i=0;i<n;i++)
        {
            p[i]=0;
        } 
        for(i=1;i<n;i++)
        {
            p[i]=p[i-1];
            if(s[i]!=s[i-1]) p[i]++;
        }
        for(i=0;i<n-w;i++)
        {
            co+=p[i+w]-p[i];
        }
        cout<<co<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,cou=0,val,flag=false;
    cin>>n>>k;
    vector<bool> a(n+1,false);
    string s;
    while(k--)
    {
        cin>>s;
        if(s=="CLICK")
        {
            cin>>val;
            if(a[val]) a[val]=false,cou--;
            else a[val]=true,cou++;
            flag=true;
        }
        else if(flag)
        {
            for(int i=1;i<=n;i++) a[i]=false;
            cou=0;
            flag=false;
        }
        cout<<cou<<'\n';
    }
    return 0;
}

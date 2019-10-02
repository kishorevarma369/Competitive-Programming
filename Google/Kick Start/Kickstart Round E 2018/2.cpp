#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll t,ans,n,m,l;
    char ch;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>n>>m>>l;
        vector<ll> v1s(l+1,0),opposing(l+1,0);
        string res(l,'0');
        set<string> myset;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>ch;
            if(ch=='1') v1s[i]++;
        }
        for(int i=0;i<m;i++)
        {
            cin>>s;
            myset.insert(s);
        }
        for(int i=0;i<l;i++)
        {
            if(v1s[i]>n-v1s[i])
            {
                res[i]='1';
                opposing[i]=n-v1s[i];
            } 
            else
            {
                opposing[i]=v1s[i];
            }
        }
        auto temp=opposing.begin();
        int baseindex=0;
        while(myset.count(res))
        {
            temp=min_element(temp,opposing.end());
            int index=(temp-opposing.begin());
            if(res[index]=='1')
            {
                res[index]='0';
                if(!myset.count(res)) opposing[index]=n-opposing[index];
                else
                {
                    res[index]='1';
                }
            }
            else
            {
                res[index]='1';
                if(!myset.count(res)) opposing[index]=n-opposing[index];
                else
                {
                    res[index]='0';
                }
            }
        }
        
        ans=0;
        cout<<"Case #"<<p<<": "<<ans<<'\n';
    }
    return 0;
}
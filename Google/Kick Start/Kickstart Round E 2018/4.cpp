#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll t,ans,n,m,l;
    char ch;
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
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
            for(int j=0;j<l;j++)
            {
                cin>>ch;
                if(ch=='1') v1s[j]++;
            }
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
        //handle equal case
        //cout<<"in equal case\n";
        if(myset.count(res))
        {
            for(int i=0;i<l;i++)
            {
                if(opposing[i]==(n-opposing[i]))
                {
                    if(res[i]=='1')
                    {
                        res[i]='0';
                        if(!myset.count(res)) break;
                        res[i]='1';
                    }
                    else
                    {
                        res[i]='1';
                        if(!myset.count(res)) break;
                        res[i]='0';
                    }
                }
            }
        }
        //cout<<"handled equal case\n";
        auto temp=opposing.begin();
        while(myset.count(res))
        {
            temp=max_element(opposing.begin(),opposing.end());
            int index=(temp-opposing.begin());
            if(res[index]=='1')
            {
                res[index]='0';
                if(!myset.count(res)) opposing[index]=n-opposing[index];
                else
                {
                    res[index]='1';
                    opposing[index]=INT64_MIN+opposing[index];
                }
            }
            else
            {
                res[index]='1';
                if(!myset.count(res)) opposing[index]=n-opposing[index];
                else
                {
                    res[index]='0';
                    opposing[index]=INT64_MIN+opposing[index];
                }
            }
        }
        ans=0;
        //cout<<res<<'\n';
        for(int i=0;i<l;i++)
        {
            if(opposing[i]<0) ans+=-(INT64_MIN-opposing[i]);
            else ans+=opposing[i];
        }
        cout<<"Case #"<<p<<": "<<ans<<'\n';
    }
    return 0;
}
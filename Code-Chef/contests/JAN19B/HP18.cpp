#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b,val,ac=0,bc=0,abc=0,tmp;
        cin>>n>>a>>b;
        map<int,int> m;
        auto it=m.begin();
        for(int i=0;i<n;i++)
        {
            cin>>val;
            it=m.find(val);
            if(it!=m.end())
            {
                tmp=it->second;
                if(tmp==1) ac++;
                else bc++;
            }
            else {
                if((val%a==0)&&(val%b==0)) abc++;
                else if(val%a==0) m[val]=1,ac++;
                else if(val%b==0) m[val]=2,bc++;
            }
        }
        if(!abc)
        {
            ac--;
        }
        if(ac>=bc) cout<<"BOB\n";
        else cout<<"ALICE\n";
    }
}
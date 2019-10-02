#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

#define uplimit 100001

ll ods[uplimit];

void pre()
{
    ll cnt=0,k,t;
    ods[0]=0;
    for(int i=1;i<uplimit;i++) ods[i]=1;
    for(int i=3;i<uplimit;i+=2)
    {
        if(ods[i]==1)
        {
            ods[i]+=i;
            for(int j=2*i;j<uplimit;j+=i)
            {
                cnt=1;
                k=i;
                t=j;
                while(t%i==0)
                {
                    t/=i;
                    cnt+=k;
                    k*=i;
                }
                ods[j]*=cnt;
            }
        }
    }
    for(int i=2;i<uplimit;i++) ods[i]+=ods[i-1];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<ods[b]-ods[a-1]<<'\n';
    }
    //Bfor(int i=1;i<10;i++) cout<<ods[i]<<'\n';
    return 0;
}

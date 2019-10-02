#include<bits/stdc++.h>

using namespace std;
vector<int> bitmask={0b111111, 0b110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b111, 0b1111111, 0b1101111};
int n;
vector<int> x(11),y(11);
int valid(int i)
{
    int bit_count;
    for(int j=0;j<n;j++)
    {
        bit_count=0;
        for(int k=0;k<7;k++)
        {
            if((bitmask[x[j]]&1<<k)&&(i&1<<k)) bit_count++;
        }
        if(bit_count!=y[j]) return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    int nt=1<<7;
    int mymin=8,mymax=-1;
    bool found=false;
    for(int i=0;i<nt;i++)
    {
        if(valid(i))
        {
            found=true;
            mymin=min(mymin,__builtin_popcount(i));
            mymax=max(mymax,__builtin_popcount(i));
        }
    }
    if(found)
    {
        cout<<7-mymax<<' '<<7-mymin<<'\n';
    }
    else cout<<"invalid\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
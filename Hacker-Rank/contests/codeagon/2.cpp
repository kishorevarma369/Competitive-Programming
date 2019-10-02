#include<bits/stdc++.h>

using namespace std;

// Complete the solve function below.

int main()
{
    unsigned long long int n,val,s,manasa=0,p;
    cin>>n;
    vector<bitset<32>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>val;
        s=1;
        for(int j=0;j<32;j++)
        {
            if(val&s) v[i][j]=1;
            s<<=1;
        } 
    }
    vector<int> known_pos(32,-1);
    for(int i=0;i<n;i++)
    {
        p=1ull;
        for(int j=0;j<32;j++)
        {
            if(v[i][j])
            {
                manasa=manasa+p*(n-i);
                //cout<<p*(n-i)<<' ';
                if(known_pos[j]!=-1)
                {
                    manasa=manasa+(i-known_pos[j])*p*(n-i);
                    known_pos[j]=-1;
                }
            }
            else if(known_pos[j]<0) known_pos[j]=i;
            p<<=1;
            //cout<<manasa<<' ';
        }
        //cout<<manasa<<'\n';
    }
    cout<<manasa<<'\n';
}
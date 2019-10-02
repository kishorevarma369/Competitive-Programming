#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,mmin=INT_MAX,mmax=INT_MIN,minpos=-1,maxpos=-1;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]>mmax)
        {
            mmax=v[i];
            maxpos=i;
        }
        if(v[i]<=mmin)
        {
            mmin=v[i];
            minpos=i;
        }
    }
    if(maxpos<minpos) cout<<maxpos+(n-1-minpos)<<'\n';
    else cout<<maxpos+(n-1-minpos)-1<<'\n';
    return 0;
}
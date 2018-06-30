#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int n,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],c1=0,c2=0;
        for(i=0;i<n;i++) cin>>a[i];
        for(i=0;i<n;i++)
        {
            
            for(j = i+1; j < n; j++)
            {
                if(a[i]>a[j]) c1++;
            }
            
        }
        for(i=1;i<n;i++)
        {
        if(a[i-1]>a[i]) c2++;
        }
        if(c1==c2) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}

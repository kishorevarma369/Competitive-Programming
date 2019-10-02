#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,sum=0,val;
    cin>>n;
    for(int i=0;i<n;i++) cin>>val,sum+=val;
    val=-1;
    for(int i=1;i<1001;i++)
    {
        if(i*n>sum){
            val=i; 
            break; 
        }
    }
    cout<<val<<'\n';
    return 0;
}
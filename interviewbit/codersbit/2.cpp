#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define mod 1000003

int solve(vector<int> &a)
{
    int odd=0,even=0,t;
    for(auto &elm:a)
    {
        if(elm&1)
        {
            t=odd; 
            odd+=even+1,even+=t;

        }
        else odd+=odd,even+=even+1;
    }
    return odd;
}


int main()
{
    vector<int> a={-4,-4,1};
    
    int ans=solve(a);
    cout<<ans<<'\n';
    return 0;
}

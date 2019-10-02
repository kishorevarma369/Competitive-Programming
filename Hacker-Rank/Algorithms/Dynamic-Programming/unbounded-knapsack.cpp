#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the unboundedKnapsack function below.
int unboundedKnapsack(int k, vector<int> arr) {
    vector<int> dp(k+1,0);
    dp[0]=1;
    // sort(arr.begin(),arr.end());
    for(auto &elm:arr)
    {
        for(int i=0;i+elm<=k;i++){
            if(dp[i]) dp[i+elm]=1;
        }
    }
    for(int i=k;i>=0;i--)
    {
        if(dp[i]) return i;
    }
    return 0;
}

int main()
{
    int t,n,k,val;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        vector<int> v;
        v.reserve(n);
        for(int j=0;j<n;j++) cin>>val,v.push_back(val);
        cout<<unboundedKnapsack(k, v)<<'\n';
    }
    return 0;
}

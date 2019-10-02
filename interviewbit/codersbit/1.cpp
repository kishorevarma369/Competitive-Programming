#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define mod 1000003

ll segtree[200002];
int n;

int xorcalc(int val)
{
    int k=val&3;
    if(k==0) return val;
    else if(k==1) return 1;
    else if(k==2) return val+1;
    return 0;
    
}
void build(vector<int> &arr)
{
    for(int i=0;i<n;i++) segtree[i+n]=xorcalc(arr[i]);
    // ,cout<<xorcalc(arr[i]);
    // cout<<'\n';
    for(int i=n-1;i>0;i--)
    {
        segtree[i]=(segtree[i*2]+segtree[2*i+1])%mod;
    }
}

void update(int node,int val)
{
    int tmpnode;
    for(segtree[node+=n]=xorcalc(val);node>0;node>>=1)
    {
        tmpnode=node/2;
        segtree[tmpnode]=(segtree[tmpnode*2]+segtree[tmpnode*2+1])%mod;
    }
}

int query(int l,int r)
{
    long long int ans=0;
    for(l+=n,r+=n;l<r;l/=2,r/=2)
    {
        if(l&1) ans+=segtree[l],l++;
        if(r&1) r--,ans+=segtree[r];
        ans%=mod;
    }
    return ans;
}



vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    n=A.size();
    build(A);
    vector<int> ans;
    ans.reserve(B.size());
    for(auto &qr:B)
    {
        if(qr[0]==1)
        {
            update(qr[1],qr[2]);
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(query(qr[1],qr[2]+1));
        }
    }
    return ans;
}

int main()
{
    vector<int> a={13,19,17,7,3,8,10,12,12};
    vector<vector<int>> b={
        {
            2,1,2
        },
        {
            1,5,19
        },
        {
            2,0,2
        },
        {
            1,4,20
        },
        {
            1,4,4
        }
    };
    vector<int> ans=solve(a,b);
    // for(int i=1;i<2*n;i++) cout<<segtree[i]<<' ';
    // cout<<'\n';
    for(auto &val:ans) cout<<val<<'\n';
    return 0;
}

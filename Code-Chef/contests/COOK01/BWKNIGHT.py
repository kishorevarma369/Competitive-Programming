t=int(input())
while(t):
    m,n=[int(x) for x in input().split()]
    prod=m*n
    ans=prod*(prod-1)
    if m > n :
        m,n = n,m
    if m == 1 : 
        ans=n*(n-1);
    else:
        ans=ans-4*((n-2)*(m-1)+(m-2)*(n-1))
    print(ans)
    t-=1
'''
#include<bits/stdc++.h>

using namespace std;
int m,n;

int ax[]={1,1,-1,-1,2,-2,2,-2};
int ay[]={2,-2,2,-2,1,1,-1,-1};

bool valid(int i,int j)
{
    if(i>=0&&i<m&&j>=0&&j<n) return true;
    return false;
}


int find_invalid(int i,int j)
{
    int cou=0;
    for(int p=0;p<8;p++)
    {
        if(!valid(i+ax[p],j+ay[p])) cou++;
    }
    return cou;
}

int main()
{
    int ans=0,prod;
    cin>>m>>n;
    prod=m*n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans+=prod-9+find_invalid(i,j);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
'''
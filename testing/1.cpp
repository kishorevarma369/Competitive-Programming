#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int a[101][101],n;

void get_input()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
}

void process()
{
    for(int i=n-2;i>0;i--) a[i][i]=INT_MAX;
    for(int i=1;i<n;i++){
        a[0][i]+=a[0][i-1];a[i][0]+=a[i-1][0];
    } 
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++) a[i][j]+=min(a[i-1][j],a[i][j-1]),a[j][i]+=min(a[j-1][i],a[j][i-1]);
    }
}

void print()
{
    for(int i=0;i<n;i++)
    {
        cout<<'\n';
        for(int j=0;j<n;j++) cout<<a[i][j]<<' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
    get_input();
    process();
    cout<<a[n-2][n-1]+a[n-1][n-2]+a[n-1][n-1]<<'\n';
    }
    
    
    // transform();
    // process();
    
    return 0;

}
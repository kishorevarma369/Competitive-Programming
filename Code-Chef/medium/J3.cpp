#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int board[505];

bool filled;
int n,k;
map<pair<int,int>,bool> blocked;

bool isPlacable(int i,int j)
{
    pair<int,int> pr={i,j};
    if(blocked.find(pr)!=blocked.end()) return false;
    for(int k=0;k<i;k++)
    {
        if(board[k]==j||abs(board[k]-j)==abs(k-i)) return false;
    }
    return true;
}

void solve(int i)
{
    if(filled) return;
    if(i==n)
    {
        for(int j=0;j<n;j++) cout<<board[j]+1<<' ';
        cout<<'\n';
        filled=true;
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(isPlacable(i,j)&&!filled){
            board[i]=j;
            solve(i+1);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        blocked.clear();
        cin>>n>>k;
        pair<int,int> pr;
        for(int i=0;i<n;i++){
            cin>>pr.first>>pr.second;
            pr.first--;
            pr.second--;
            blocked[pr]=true;
        }
        filled=false;
        solve(0);
    }
    return 0;
}
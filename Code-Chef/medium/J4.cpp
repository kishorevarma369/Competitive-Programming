#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int board[505];

bool filled;
int n,k;
map<pair<int,int>,bool> blocked;

bool inbtwn(pair<int,int> a,int p,int q,int i,int j)
{
    int x,y;
    tie(x,y)=a;
    if(p==i)
    {
        if(p!=x) return false;
        if(q>j) swap(q,j);
        if(q<x&&x<j) return true;
        else return false;
    }
    if(q==j)
    {
        if(q!=y) return false;
        if(p>i) swap(p,i);
        if(p<y&&y<i) return true;
        else return false;
    }
    //diagonal case 
    if()
    if(i-p>0&&j-q>0)
    {

    }
    else
    {
        
    }
    
    return true;
}

bool isPlacable(int i,int j)
{
    pair<int,int> pr={i,j};
    if(blocked.find(pr)!=blocked.end()) return false;
    int p,q;
    bool found;
    for(int k=0;k<i;k++) // for each column filled till now
    {
        p=board[k],q=k;
        //(p,q) (i,j)
        if(p==i||q==j||abs(p-i)==abs(q-j))
        { 
            //queens can attack each other
            //check for blocked square
            found=false;
            for(auto &block:blocked)
            {
                if(inbtwn(block.first,p,q,i,j))
                {
                    found=true;
                    break;
                }
            }
            if(!found) return false;
        }
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
    for(int j=0;j<n;j++)//each row
    {
        if(isPlacable(j,i)&&!filled){
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
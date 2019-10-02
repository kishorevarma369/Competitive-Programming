#include<bits/stdc++.h>

using namespace std;
map<int,int> ladder,snake;
void print_board(vector<int> &board)
{
    for(int i=1;i<101;i++)
    {
        if((i-1)%10==0) cout<<'\n';
        cout<<' '<<board[i]<<' '; 
    }
}

void dfs(vector<int> &board,int node)
{
    queue<int> q;
    int k=0,level;
    board[node]=0;
    auto sit=snake.begin();
    auto lit=ladder.begin();
    q.push(node);
    while(!q.empty())
    {
        node=q.front();
        level=board[node];
        q.pop();
        k=node+6;
        for(int i=node+1;i<=k&&i<=100;i++)
        {
            if(board[i]) continue;
            lit=ladder.find(i);
            sit=snake.find(i);
            if(lit!=ladder.end())
            {
                if(!board[lit->second]){
                    q.push(lit->second);
                    board[i]=level+1;
                    board[lit->second]=level+1;
                } 
            }
            else if(sit!=snake.end())
            {
                //at snake
                if(!board[sit->second]){
                    q.push(sit->second);
                    board[i]=level+1;
                    board[sit->second]=level+1;
                } 
            }
            else
            {
                q.push(i);
                board[i]=level+1;
            } 
        }
    }
}

int main()
{
    int t,n,m,b,e;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        vector<int> board(101,0);
        ladder.clear();
        snake.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>b>>e;
            ladder[b]=e;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>b>>e;
            snake[b]=e;
        }
        dfs(board,1);
        if(board[100]==0) cout<<"-1\n";
        else cout<<board[100]<<'\n';
        //print_board(board);
    }
    return 0;
}
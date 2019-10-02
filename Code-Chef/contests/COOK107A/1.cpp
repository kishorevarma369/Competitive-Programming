#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef unsigned long long int llu;
int r,c;

bool isvalid(tuple<int,int,char> &p)
{
    int x,y;
    char direction;
    tie(x,y,direction)=p;
    if(x>=0&&x<r&&y>=0&&y<c) return true;
    return false;
}

void move_ant(tuple<int,int,char> &ant)
{
    int x,y;
    char direction;
    tie(x,y,direction)=ant;
    if(direction=='U') x--;
    else if(direction=='D') x++;
    else if(direction=='R') y++;
    else y--;
    get<0>(ant)=x;
    get<1>(ant)=y;    
}

void fun()
{
    
    cin>>r>>c;
    vector<string> board(r);
    vector<tuple<int,int,char>> ants[2];
    bool turn=0;
    char ch;
    for(int i=0;i<r;i++)
    {
        cin>>board[i];
        for(int j=0;j<c;j++)
        {
            ch=board[i][j];
            if(ch=='U'||ch=='D'||ch=='L'||ch=='R'){
                ants[turn].push_back({i,j,ch});
                board[i][j]='-';
            }
        }
    }
    int no_of_meets=0;
    while(ants[turn].size())
    {
        map<pair<int,int>,int> mymap;
        int x,y;
        char direction;
        ants[!turn].clear();
        for(auto &ant:ants[turn])
        {
            move_ant(ant);
            tie(x,y,direction)=ant;
            if(isvalid(ant)&&board[x][y]=='-'){
                ants[!turn].push_back(ant);
                mymap[{x,y}]++;
            }
        }
        turn=turn^1;
        for(auto &pr:mymap){
            no_of_meets+=(pr.second*(pr.second-1))/2;
        }
    }
    cout<<no_of_meets<<'\n';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)  fun();
    return 0;
}
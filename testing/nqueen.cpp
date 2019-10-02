#include<bits/stdc++.h>

using namespace std;

struct point{
    int x,y;
    point(){
    x=0;y=0;
    };
    point(int a,int b)
    {
        x=a,y=b;
    };
};

int n=50;//correspond to no of queens

bool isvalid(vector<point> s,int row,int col)
{
    int dx,dy;
    for(auto p:s)
    {
        dx=abs(p.x-row);
        dy=abs(p.y-col);
        if(dx==0||dy==0||dx==dy) return false;
    }
    return true;
}
 int index=0;
void print(vector<point> &s)
{
   
    cout<<"\nSolution "<<index++<<" :\n";
    vector<vector<bool>> v(n,vector<bool>(n));
    for(auto p:s)
    {
        v[p.x][p.y]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]) cout<<'1';
            else cout<<'0';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void n_queen(vector<point> s,int level=0)
{
    if(level==n)
    {
        index++;
        // print(s);
    }
    for(int i=0;i<n;i++)
    {
        if(isvalid(s,level,i)){
            s.push_back(point(level,i));
            n_queen(s,level+1);
            s.pop_back();
        }
    }
}

int main(){
    vector<point> s;
    n_queen(s);
    cout<<index<<'\n';
    return 0;
}

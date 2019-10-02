#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.

float slope(int x1,int y1,int x2,int y2)
{
    return abs(float(y2-y1)/(x2-x1))
}

void solve(vector<vector<int>> &grid) {
    for(int i=0;i<5;i++)
    {
        map<float,int> mymap;
        int nanc=0,c=0;
        for(int j=0;j<5;j++)
        {
            if(i==j) continue;
            auto v=abs(slope(grid[i][0],grid[i][1],grid[j][0],grid[j][1]));
            if(isnan(v)) nanc++;
            else
            {
                mymap[v]++;
            }
        }
        if(nanc)
        {
            if(nanc>2)
            {
                cout<<"No\n";
                return;
            }
            else if(nanc==2)
            {
                c++;
            }
        }
        for(auto &p:mymap)
        {
            if(p.second>2)
            {
                cout<<"No\n";
                return;
            }
            else if(p.second==2)
            {
                c++;
            }
        }
        if(c!=1)
        {
            cout<<"No\n";
                return;
        }
        else if(c==2)
        {
            
        }
    }
    
}

int main()
{
    int t;
    cin>>t;
    vector<vector<int>> v(5,vector<int>(2))
    while(t--)
    {
        for(int i=0;i<5;i++)
        {
            cin>>v[i][0]>>v[i][1];
        }
        solve(v)
    }
}
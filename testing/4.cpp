#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<string> notpossible={"grid","snot","poss","ible"} ;
vector<string> tofill;
vector<string> ans={"----","----","----","----"};
set<string> found;
int n;

void solve(vector<string> grid,vector<bool> state)
{
    for(int i=0;i<n;i++)
    {
        if(!state[i])
        {
            vector<string> presgrid=grid;
            //row insertion
            for(int j=0;j<4;j++)
            {
                if(grid[j][0]==tofill[i][0])
                {
                    
                }
            }

            //col insertion


        }
    }
}

int main()
{
    cin>>n;
    string s,tmp;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        tmp=s;
        reverse(tmp.begin(),tmp.end());
        if(found.find(s)==found.end()&&found.find(tmp)==found.end())
        {
            found.insert(s);
            tofill.push_back(s);
        }
    }
    found.clear();
    n=tofill.size();
    solve(ans,vector<bool>(n,false));
    return 0;
}
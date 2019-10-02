#include<bits/stdc++.h>

using namespace std;


int solve(int A, int B, int C, int D, vector<string> &E) {
    queue<pair<int,int>> q;
    vector<vector<int>> visited(E.size(),vector<int>(E[0].size(),-1));
    A--,B--,C--,D--;
    q.push(make_pair(A,B));
    visited[A][B]=0;
    int ax[]={0,1,0,-1};
    int ay[]={1,0,-1,0};
    int m=E.size(),n=E[0].size(),vcost;
    pair<int,int> point,np;
    while(!q.empty())
    {
        np=point=q.front();
        vcost=visited[np.first][np.second];
        q.pop();
        for(int i=0;i<4;i++)
        {
            np.first=point.first+ax[i];
            np.second=point.second+ay[i];
            while(np.first>=0&&np.first<m&&np.second>=0&&np.second<n&&E[np.first][np.second]=='0')
            {
                if(visited[np.first][np.second]!=-1)
                {
                   if(visited[np.first][np.second]<=vcost+1){
                     np.first+=ax[i];
                    np.second+=ay[i];
                      continue;
                   }
                }
                visited[np.first][np.second]=vcost+1;
                q.push(np);
                np.first+=ax[i];
                np.second+=ay[i];
            }
        }
    }
    return visited[C][D];
}


int main()
{
  vector<string> v= {"0000000000", "0111111110", "0000100010", "0000100000", "0000000010", "0000100100", "0000100010", "0000100100", "0010001010", "1000101000" };
  for(auto &s:v) cout<<s<<'\n';
  cout<<solve(1,1,3,6,v);
    return 0;
}
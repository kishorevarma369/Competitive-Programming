#include <bits/stdc++.h>

using namespace std;
//first i used string compare 1 test case failed
/*
  because

  as
  bf

  if string is compared we get true because a<b , but s<f is not true .
*/
string gridChallenge(vector <string> &grid)
{
    sort(grid[0].begin(),grid[0].end());
    int n=grid.size(),len=grid[0].size();
    for(int i=1;i<n;i++)
    {
      sort(grid[i].begin(),grid[i].end());
      for(int j=0;j<len;j++)
      {
        if(grid[i][j]<grid[i-1][j])
        {
          return string("NO");
        }
      }
    }
    return string("YES");
}

int main() {
    int t;
    cin >> t;
    int n;

    while(t--)
    {
            cin >> n;
    vector<string> grid(n);
        for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    string result = gridChallenge(grid);
    cout << result << endl;
    }

    return 0;
}

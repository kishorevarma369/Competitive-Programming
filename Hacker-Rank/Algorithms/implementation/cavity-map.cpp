#include <bits/stdc++.h>

using namespace std;

vector <string> cavityMap(vector <string> grid)
{
    vector<string> res=grid;
    int si=grid.size()-1;
    for(int i=1;i<si;i++)
    {
        int ma=grid[i].size()-1;
        for(int j=1;j<ma;j++)
        {
            if(grid[i][j-1]<grid[i][j]&&grid[i][j+1]<grid[i][j]&&grid[i-1][j]<grid[i][j]&&grid[i+1][j]<grid[i][j]) res[i][j]='X';
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    vector <string> result = cavityMap(grid);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}

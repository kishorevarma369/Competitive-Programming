#include <bits/stdc++.h>

using namespace std;

long raceAgainstTime(int n,int p,int mason_height, vector <int>& heights, vector <int>& prices,long total)
{
    int i,j,c_height=mason_height,k,l;
    for(i=p;i<n;i++)
    {
      if(prices[i]<0)
      {
        if(heights[i]>=c_height)
        {
          total+=heights[i]-c_height+prices[i];
          c_height=heights[i];
          continue;
        }
        else
        {
            k=raceAgainstTime(n,i+1, c_height, heights, prices,total);
            total+=abs(c_height-heights[i])+prices[i];
            c_height=heights[i];
            l=raceAgainstTime(n,i+1, c_height, heights, prices,total);
            return min(k,l);
        }
      }
      if(heights[i]>c_height)
      {
        total+=heights[i]-c_height+prices[i];
        c_height=heights[i];
      }
    }
    return total+n+1;
}

int main() {
    int n;
    cin >> n;
    int mason_height;
    long total=0;
    cin >> mason_height;
    vector<int> heights(n-1);
    for(int heights_i = 0; heights_i < n-1; heights_i++){
       cin >> heights[heights_i];
    }
    vector<int> prices(n-1);
    for(int prices_i = 0; prices_i < n-1; prices_i++){
       cin >> prices[prices_i];
    }
    long result = raceAgainstTime(n-1,0, mason_height, heights, prices,total);
    cout << result << endl;
    return 0;
}

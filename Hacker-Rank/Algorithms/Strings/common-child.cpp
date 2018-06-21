#include <bits/stdc++.h>

using namespace std;

inline int fun(int size,vector<vector<int>>& table,int i,int j)
{
  if(i<0||j<0) return 0;
  return table[i][j];
}

int commonChild(string s1, string s2)
{
    int size=s1.size(),i,j;
    vector<vector<int>> table(size,vector<int>(size,0));
    for(i=0;i<size;i++)
    {
      for(j=0;j<size;j++)
      {
        if(s1[i]==s2[j])
        {
          table[i][j]=fun(size,table,i-1,j-1)+1;
        }
        else table[i][j]=max(fun(size,table,i-1,j),fun(size,table,i,j-1));
      }
    }
    return table[size-1][size-1];
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}

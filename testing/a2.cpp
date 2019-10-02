#include <bits/stdc++.h>
using namespace std;
int a[3][3];
int fun(string s)
{
  int i, j, k = 0, c = 0;
  //printf("---------------\n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      //cout<<s[k]<<" ";
      c += abs(a[i][j] - (s[k++] - '0'));
    }
    //  cout<<"\n";
  }
  // printf("---------------\n");
  return c;
}
int main()
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  string s = "123456789";
  vector<string> v;
  int r, val;
  int t = 100000;
  do
  {
    val = s[0] + s[1] + s[2];
    if ((val == s[3] + s[4] + s[5]) && (val == s[6] + s[7] + s[8]) && (val == s[0] + s[3] + s[6]) && (val == s[1] + s[4] + s[7]) && (val == s[2] + s[5] + s[8]) && (val == s[0] + s[4] + s[8]) && (val == s[2] + s[4] + s[6]))
    {
      v.push_back(s);
    }
  } while (next_permutation(s.begin(), s.end()));
  for (i = 0; i < v.size(); i++)
  {
    r = fun(v[i]);
    if (t > r)
    {
      t = r;
    }
  }
  cout << t;
}
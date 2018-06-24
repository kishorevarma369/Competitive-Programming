/*
Paying up 

https://www.codechef.com/problems/MARCHA1
*/

#include <bits/stdc++.h>
using namespace std;

int fun1(vector<int> &v,int val, int j)
{
  if (val == 0) return 1;
  else if (j >= v.size() || val < 0 || val < v[j])
    return 0;
  if (fun1(v,(val - v[j]), j + 1)||fun1(v,val, j + 1)) return 1;
  return 0;
}

void fun()
{
  int m,n, i, j = INT_MAX, k = 0;
  cin >> n >> m;
  std::vector<int> v(n);
  for (i = 0; i < n; i++)
  {
    cin >> v[i];
    if (v[i] < j)
      j = v[i];
    k += v[i];
  }
  if (k < m || j > m)
    cout << "No\n";
  else if (k == m)
    cout << "Yes\n";
  else
  {
    sort(v.begin(), v.end());
    if (fun1(v,m, 0))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}

int main(int argc, char const *argv[])
{
  
  int n;
  cin >> n;
  while (n--)
    fun();
  return 0;
}

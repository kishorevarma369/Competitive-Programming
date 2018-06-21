#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > &s, int d, int m)
{
  int i,j=0,val=0,count=0;
  for(i=0;i<m;i++) val+=s[i];
  if(val==d) count++;
  for(i=m;i<n;i++,j++)
  {
    val=val-s[j]+s[i];
    if(val==d) count++;
  }
  return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}

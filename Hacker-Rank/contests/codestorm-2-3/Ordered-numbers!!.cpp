/*
https://www.hackerrank.com/contests/codestorm-2-3/challenges/ordered-numbers
*/
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n,i;
  cin>>n;
  vector<string> v(n);
  for(i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  for(i=0;i<n;i++) cout<<v[i]<<'\n';
  return 0;
}

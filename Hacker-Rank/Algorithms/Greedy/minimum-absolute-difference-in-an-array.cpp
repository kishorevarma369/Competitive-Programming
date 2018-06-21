#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  long long int n,i,min=INT_MAX;
  cin>>n;
  std::vector<int> v(n);
  for(i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  for (i = 1; i < n; i++)
  {
    if(abs(v[i]-v[i-1])<min) min=abs(v[i]-v[i-1]);
  }
  cout<<min;
  return 0;
}

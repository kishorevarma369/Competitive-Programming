#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  int i, k,q;
  vector<int> a(n);
  for(i=0;i<n;i++) cin>>a[i];
  sort(a.begin(),a.end());
  for(i=1;i<n;i++) a[i]+=a[i-1];
  cin>>k;
  while(k--)
  {
    cin>>q;
    i=ceil(float(n)/(q+1));
    cout<<a[i-1]<<'\n';
  }
  return 0;
}

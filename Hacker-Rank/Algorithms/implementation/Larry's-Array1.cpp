#include<bits/stdc++.h>

using namespace std;

void fun()
{
  int n,i,count=0;
  cin>>n;
  vector<int> a(n);
  int c[n+1];
  c[0]=0;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
    c[a[i]]=i;
  }
  sort(a.begin(),a.end());
  for(i=0;i<=n;i++)
  {
    count+=c[i];
  }
  cout<<count-n;
  if((count-2*n)%3==0) cout<<"YES\n";
  else cout<<"NO\n";
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,k,l;
  cin>>n;
  while(n--)
  {
    cin>>k;
    if(k<38)
    {
      cout<<k<<'\n';
      continue;
    }
    l=int(5*ceil(float(k)/5));
    if(l-k<3)  k=l;
    cout<<<<'\n';

  }
  return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,k,p;
  cin>>n;
  while(n--)
  {
    long long int a,b,c;
    cin>>a>>b>>c;
    k=(b+c);
    if(a==2)
    {
      if(k%3==0) cout<<"YES\n";
      else cout<<"NO\n";
      continue;
    }
    switch((a-3)%4)
    {
      case 0:p=2;
          break;
      case 1:p=4;
          break;
      case 2:p=8;
          break;
      case 3:p=6;
          break;
    }
    k=(k%3+((k%10)%3*p)%3)%3;
    if(k==0) cout<<"YES\n";
    else  cout << "NO" << '\n';
  }
  return 0;
}

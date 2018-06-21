#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  unsigned long long int i,n;
  cin>>n;
  while(n--)
  {
    cin>>i;
    i/=7;
    cout<<(7*i*(i+1))/2<<'\n';
  }
  return 0;
}

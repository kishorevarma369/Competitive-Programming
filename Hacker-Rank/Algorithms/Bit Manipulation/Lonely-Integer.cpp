#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,j,k;
  cin>>n;
  cin>>j;
  k=j;
  while(--n)
  {
    cin>>j;
    k^=j;
  }
  cout<<k;
  return 0;
}

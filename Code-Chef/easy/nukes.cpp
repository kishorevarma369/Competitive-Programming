#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int a,n,k,i=0;
  cin>>a>>n>>k;
  n++;
  while(i<k)
  {
    cout<<a%n<<' ';
    a/=n;
    i++;
  }
  return 0;
}

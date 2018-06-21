#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  cin.tie(NULL);
  /*
  int t,n,op,i,j;
  cin>>n>>t;
  vector<int> v(n,0);
  while(t--)
  {
    cin>>op>>i>>j;
  }*/
  //vector<vector<int>> v()
  int n=1,k;
  for(;n<20;n++)
  {
    k=ceil(sqrt(n));
    cout<<n<<' '<<k<<' '<<ceil(float(n)/k)<<'\n';
  }
  return 0;
}

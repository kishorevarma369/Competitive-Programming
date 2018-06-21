#include<bits/stdc++.h>
using namespace std;
//Buying Sweets
void fun()
{
    int n,cost,sum=0,i,t=0;
    cin>>n>>cost;
    vector<int> v(n);
    for(i=0;i<n;i++)
    {
      cin>>v[i];
      sum+=v[i];
    }
    t=sum/cost;
    for(auto &i:v)
    {
      if((sum-i)/cost>=t)
      {
        cout<<-1<<'\n';
        return;
      }
    }
    cout<<t<<'\n';
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}

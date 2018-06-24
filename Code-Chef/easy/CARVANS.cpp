#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,i,j;
  cin>>n;
  while(n--)
  {
    int cars,speed,m=INT_MAX,c=0;
    cin>>cars;
    for(i=0;i<cars;i++)
    {
      scanf("%d",&speed);
      if(speed<=m)
      {
        c++;
        m=speed;
      }
    }
    cout<<c<<'\n';
  }
  return 0;
}

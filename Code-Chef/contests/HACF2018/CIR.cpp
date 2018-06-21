#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int cx1,cy1,cx2,cy2,r1,r2,n,dc,dr,dr1;
  cin>>n;
  while(n--)
  {
    cin>>cx1>>cy1>>r1;
    cin>>cx2>>cy2>>r2;
    dc=(cx1-cx2)*(cx1-cx2)+(cy1-cy2)*(cy1-cy2);
    dr=(r1-r2)*(r1-r2);
    dr1=(r1+r2)*(r1+r2);
    if(dc==dr||dc==dr1)
    {
      cout<<"tangential\n";
    }
    else if(dc<=dr1&&dc>=dr)
    {
      cout<<"overlapping\n";
    }
    else cout<<"not overlapping\n";
  }
  return 0;
}

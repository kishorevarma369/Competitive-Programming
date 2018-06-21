#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(unsigned long long int a,unsigned long long int b)
{
  return a>b;
}

void fun()
{
    int n,i,j,flag=1;
    cin>>n;
    unsigned long long int a[n][n],sum=0,sum1=0,checksum=0;
    vector<unsigned long long int> containers(n),balls(n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>a[i][j];
    for(i=0;i<n;i++)
    {
      sum=sum1=0;
      for(j=0;j<n;j++)
      {
        sum+=a[j][i];
        sum1+=a[i][j];
      }
      containers.push_back(sum);
      balls.push_back(sum1);
    }
    sort(containers.begin(),containers.end(),check);
    sort(balls.begin(),balls.end(),check);
    if(containers==balls) cout<<"Possible\n";
    else cout<<"Impossible\n";
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}

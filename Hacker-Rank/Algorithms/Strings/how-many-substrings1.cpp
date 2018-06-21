#include<bits/stdc++.h>
using namespace std;

void fun()
{
  int n;
  cin>>n;
  string s,tmp="";
  cin>>s;
  int size=s.size(),k,i,count=0,j;
  vector<vector<int>> cou(size);
  vector<string> strhld(size);
  map<string,int> tmap;
  for(i=0;i<size;i++)
  {
      tmp+=s[i];
      strhld[i]=tmp;
      cou[0][i]=cou[0][i?i-1:0]
  }
  for(i=1;i<size;i++)
  {
    map<string,int> amap;
    string tmp="";
    for(j=i;j<size;j++)
    {
      tmp+=s[j];
      amap[tmp]++;
    }
  }
  cout<<count<<'\n';
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--)
  {
    fun();
  }
  return 0;
}

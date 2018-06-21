#include<bits/stdc++.h>
using namespace std;

void fun()
{
    int n,i=0;
    char ch;
    vector<vector<int>> v(26);
    while((ch=getchar())!='\n')
    {
      v[ch-'a'].push_back(i);
      i++;
    }
    cin>>n;
    for(auto &p:v)
    {
      for()
    }
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  while(n--) fun();
  return 0;
}

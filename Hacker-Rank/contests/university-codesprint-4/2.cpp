#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> initialize(vector<int> t)
{
    vector<vector<int>> table(t.size(),vector<int>(t.size(),0));
    map<int,int> v;
    auto size=t.size();
    auto i=0,j=0,k=0,count=0;
    for(i=0;i<size;i++) table[i][i]=1;
    for(i=0;i<size;i++)
    {
      map<int,int> mymap;
      for(j=0;j<=i;j++) mymap[t[j]]+=1;
      count=0;
      for(auto l:mymap) if(l.second==1) count++;
      table[0][i]=count;
      for(k=0;j<size;j++)
      {
        if(mymap[t[k]]==1) count--;
        mymap[t[k]]--;
        if(mymap[t[k]]==1) count++;
        mymap[t[j]]++;
        if(mymap[t[j]]==1) count++;
        k++;
        table[k][k+i]=count;
      }
    }
    return table;
}



int main()
{
    int i,j,n,t;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++) cin>>v[i];
    auto table=initialize(v);
    /*for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++) cout<<table[i][j]<<' ';
      cout<<'\n';
    }*/
    cin>>t;
    while(t--)
    {
      cin>>i>>j;
      i--,j--;
      cout<<table[i][j];
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void initialize(vector<long> t,vector<vector<long>> &table)
{

    auto size=t.size();
    long i=0,j=0,k=0,count=0;
    for(i=0;i<size;i++)
    {
      vector<long> v(size-i,0);
      v[0]=1;
      table.push_back(v);
    }
    for(i=1;i<size;i++)
    {
      unordered_map<long,long> mymap;
      for(j=0;j<=i;j++) mymap[t[j]]+=1;
      count=0;
      for(auto l:mymap) if(l.second==1) count++;
      table[0][i]=count;
      auto it=mymap.begin();
      for(k=0;j<size;j++)
      {
        it=mymap.find(t[k]);
        if(it->second==1)
        {
          count--;
          mymap.erase(it);
        }
        else
        {
          (it->second)--;
          if(it->second==1) count++;
        }
        if(mymap[t[j]]==1) count--;
        mymap[t[j]]++;
        if(mymap[t[j]]==1) count++;
        k++;
        table[k][i]=count;
      }
    }
}



int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);
    int i,j,n,t;
    cin>>n;
    vector<long> v(n);
    for(i=0;i<n;i++) cin>>v[i];
    vector<vector<long>> table;
    initialize(v,table);
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
      cout<<table[i][j-i]<<'\n';
    }
    return 0;
}

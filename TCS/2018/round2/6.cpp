#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int>  split(const std::string& str) {
    vector<int> v;
  stringstream ss(str);
  ss >> std::noskipws;
  int field;
  char ws_delim;
  while(1) {
    if( ss >> field )
      v.push_back(field);
    else if (ss.eof())
      break;
    ss.clear();
    ss >> ws_delim;
  }
  return v;
}

int cmp(pair<int,vector<int>> &a,pair<int,vector<int>> &b)
{
    if(a.second.size()==b.second.size())
    {
        if(a.second.size()==2) return 0;
        else return a.second.back()<b.second.back();
    }
    return a.second.size()>b.second.size();
}

int cmp1(pair<int,vector<int>> &a,pair<int,vector<int>> &b)
{
    return a.first<b.first;
}

void sum(vector<vector<int>> &sa,vector<vector<int>> &sb)
{
    for(int i=0;i<sb.size();i++)
    {
        for(int j=0;j<sb.size();j++)
        {
            sb[i][j]+=sa[i][j];
        }
    }
}

int main()
{
    int n,r,t,q;
    cin>>n>>r;
    vector<vector<vector<int>>> scores(r,vector<vector<int>>(n,vector<int>(n,0)));
    vector<pair<int,vector<int>>> queries,sq;
    t=n*(n-1)*r;
    t/=2;
    char ch;
    int p1,p2,rnum;
    float s1,s2;
    while(t--)
    {
        cin>>ch>>p1>>ch>>p2>>s1>>s2>>rnum;
        p1--,p2--,rnum--;
        scores[rnum][p1][p2]=int(s1);
        scores[rnum][p2][p1]=int(s2);
    }
    string line;
    cin>>q;
    for(int i=0;i<=q;i++)
    {
        getline(cin, line);
        auto tmpv=split(line);
        //for(auto number:tmpv) cout<<number<<'\n';
        if(tmpv.size()==3) queries.push_back({i,tmpv});
        else sq.push_back({i,tmpv});
    }
    // for(auto query:queries)
    // {
    //     for(auto number:query.second) cout<<number<<' ';
    //     cout<<'\n'; 
    // }
    sort(queries.begin(),queries.end(),cmp);
    auto it=queries.begin();
    int i=0,tval;
    while(i<r)
    {
        mloop:
        while(it!=queries.end())
        {
            auto &tmp=it->second;
            if(tmp.back()-1==i) 
            {
                tval=0;
                for(auto &sval:scores[i][tmp[0]-1]) tval+=sval;
                for(auto &sval:scores[i][tmp[1]-1]) tval-=sval;
                tmp.push_back(tval);
                it++;
                goto mloop;
            }
            else break;
        }
        if(i+1<r) sum(scores[i],scores[i+1]);
    }
    sort(queries.begin(),queries.end(),cmp1);
    
    return 0;
}
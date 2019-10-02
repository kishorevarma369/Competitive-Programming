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

void sum(vector<float> &sa,vector<float> &sb)
{
    for(int i=0;i<sb.size();i++)
    {
        sb[i]+=sa[i];
    }
}

int main()
{
    int n,r,t,q;
    cin>>n>>r;
    vector<vector<float>> scores(r,vector<float>(n,0));
    vector<pair<int,vector<int>>> queries,sq;
    vector<float> res1,res2;
    t=n*(n-1)*r;
    t/=2;
    char ch;
    int p1,p2,rnum;
    float s1,s2;
    while(t--)
    {
        cin>>ch>>p1>>ch>>p2>>s1>>s2>>rnum;
        p1--,p2--,rnum--;
        scores[rnum][p1]+=s1;
        scores[rnum][p2]+=s2;
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
    int i=0;
    float tval;
    map<int,float> threeres;
    while(i<r)
    {
        mloop:
        while(it!=queries.end())
        {
            auto &tmp=it->second;
            if(tmp.back()-1==i) 
            {
                tval=scores[i][tmp[0]-1]-scores[i][tmp[1]-1];
                threeres[it->first]=tval;
                it++;
                goto mloop;
            }
            else break;
        }
        if(i+1<r) sum(scores[i],scores[i+1]);
        i++;
    }
    sort(queries.begin(),queries.end(),cmp1);
    float tvals=0;
    int flag=0;
    for(auto &ech:sq)
    {
        auto &t=ech.second;
        tvals=0;
        flag=0;
        for(int i=0;i<t.size();i++)
        {
            if(i&1) tvals+=scores[r-1][t[i]-1];
            else tvals-=scores[r-1][t[i]-1];
            flag=1;
        }
        //cout<<'\n';
        if(flag) res2.push_back(tvals);
    }
    int maxscore,maxplayer=0,minscore,minplayer=0;
    auto it1=sq.end();
    auto it2=res2.begin();
    for(int i=0;i<q;i++)
    {
        if(it1!=sq.end()&&it1->first==i)
        {
            cout<<*it2<<'\n';
            it2++;
            it1++;
        }
        else
        {
            cout<<threeres[i]<<'\n';
        }
    }
    return 0;
}
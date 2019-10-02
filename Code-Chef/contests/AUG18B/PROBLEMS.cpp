#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007ll

typedef long long int ll;
vector<pair<int,int>> tests;
vector<int> v,v1;

class problems 
{
    public:
    int problem_no;
    int difficulty;
    problems(int no,int n)
    {
        difficulty=0;
        problem_no=no;        
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++) cin>>v1[i];
        for(int i=0;i<n;i++) tests[i]=make_pair(v[i],v1[i]);
        sort(tests.begin(),tests.end(),[](const pair<int,int> &p,const pair<int,int> &q){return get<0>(p)<get<0>(q);});
        int x,y,p,q;
        for(int i=1;i<n;i++)
        {
            tie(x,y)=tests[i];
            tie(p,q)=tests[i-1];
            if(y<q) difficulty++;
        }
    }
    
};

int compfun(problems &p,problems &q)
{
    if(p.difficulty==q.difficulty) return p.problem_no<q.problem_no;
    return p.difficulty<q.difficulty;
}

int main(int argc, char const *argv[])
{
    vector<problems> v;
    int np,nt;
    cin>>np>>nt;
    tests.resize(nt);
    v.resize(nt);
    v1.resize(nt);
    for(int i=0;i<np;i++)
    {
        problems p(i,nt);
        v.push_back(p);
    }
    sort(v.begin(),v.end(),compfun);
    for(int i=0;i<np;i++) cout<<v[i].problem_no+1<<'\n';
    return 0;
}

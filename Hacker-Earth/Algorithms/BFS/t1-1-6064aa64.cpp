/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/t1-1-6064aa64/
Question : Permutation
Solution by :Kishore Varma
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define mod 100000

void solve()
{
    int n;
    string s,f;
    char ch;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ch,s.push_back(ch);
    f=s;
    sort(f.begin(),f.end());
    queue<string> q;
    map<string,int> visited;
    q.push(s);
    visited[s]=0;
    if(s==f){
         cout<<"0\n";
        return;
    }
    // cout<<s<<' '<<f<<'\n';
    while (!q.empty())
    {
        auto pres=q.front();
        auto pres_cost=visited[pres];
        q.pop();
        for(int i=1;i<n;i++)
        {
            auto tmp=pres;
            reverse(tmp.begin(),tmp.begin()+i+1);
            auto it=visited.find(tmp);
            if(it==visited.end())
            {
                q.push(tmp);
                visited[tmp]=pres_cost+1;
            }
            else
            {
                if(it->second>pres_cost+1)
                {
                    q.push(tmp);
                    it->second=pres_cost+1;
                }
            }
        }
    }
    cout<<visited[f]<<'\n';
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}


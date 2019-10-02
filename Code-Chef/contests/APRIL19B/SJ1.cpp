#include<bits/stdc++.h>

using namespace std;

#define uplim 100001

typedef unsigned long long int ll;

ll val[uplim],mods[uplim];
int t,n;
vector<int> children[uplim];
bool visited[uplim];
vector<pair<int,int>> mystack;
vector<pair<ll,ll>> finalAnswer;

void make_tree()
{
    int e1,e2;
    for(int i=0;i<=n;i++) children[i].clear(),visited[i]=false;
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        children[e1].push_back(e2);
        children[e2].push_back(e1);
    }
}

ll find_ans(ll mod)
{
    ll nodeval,mymax=0,g=val[mystack[0].first];
    int node,i=0,j=mystack.size();
    while(i<j)
    {
        node=mystack[i].first;
        nodeval=val[node];
        g=__gcd(nodeval,g);
        i++;
    }
    return mod-__gcd(g,mod);
}

void solve()
{
    finalAnswer.clear();
    cin>>n;
    make_tree();
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=n;i++) cin>>mods[i];
    mystack.clear();
    mystack.push_back({1,0});
    visited[1]=true;
    int node;
    while(mystack.size())
    {
        node=mystack.back().first;
        auto &toprocess=mystack.back().second;
        auto &childlist=children[node];
        if(childlist.size()==1&&node!=1)
        {
            finalAnswer.push_back({(ll)node,find_ans(mods[node])});
            toprocess=1;
        }
        else
        {
            for(;toprocess<childlist.size();toprocess++)
            {
                if(visited[childlist[toprocess]]) continue;
                mystack.push_back(make_pair(childlist[toprocess],0));
                visited[childlist[toprocess]]=true;
                break;
            }
        }
        if(toprocess==childlist.size())
        {
            mystack.pop_back();
        }
    }
    sort(finalAnswer.begin(),finalAnswer.end());
    for(auto &ans:finalAnswer)
    {
        cout<<ans.second<<' ';
    }
    cout<<'\n';
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    mystack.reserve(uplim+10);
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
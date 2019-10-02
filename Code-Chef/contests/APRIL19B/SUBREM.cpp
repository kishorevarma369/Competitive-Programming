#include<bits/stdc++.h>

using namespace std;

#define uplim 100001

typedef long long int ll;

ll x,ans[uplim],values[uplim],tans[uplim];
int parent[uplim];
int n;
vector<int> children[uplim];
vector<int> mystack;
vector<int> sp;

void construct_tree()
{
    int e1,e2;
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        children[e1].push_back(e2);
        children[e2].push_back(e1);
    }
}

void solve()
{
    cin>>n>>x;
    assert(n<uplim);  
    for(int i=1;i<=n;i++){
        cin>>values[i]; 
        tans[i]=values[i]; 
        parent[i]=-1;
        ans[i]=INT64_MIN;
        children[i].clear();
    }
    construct_tree();
    mystack.push_back(1);
    sp.push_back(0);
    parent[1]=0;
    int node,child;
    while(mystack.size())
    {
        node=mystack.back();
        auto &toprocess=sp.back();
        auto &childrenlist=children[node];
        for(;toprocess<childrenlist.size();toprocess++)
        {
            if((child=childrenlist[toprocess]))
            {
                if(parent[child]==-1)
                {
                    parent[child]=node;
                }
                if(child==parent[node]) continue;
                if(ans[child]==INT64_MIN)
                {
                    mystack.push_back(child);
                    sp.push_back(0);
                    break;
                }
                else
                {
                    tans[node]+=ans[child];
                }
            }
        }
        if(toprocess==childrenlist.size())
        {
            ans[node]=max(-x,tans[node]);
            mystack.pop_back();
            sp.pop_back();
        }
    }
    cout<<ans[1]<<'\n';
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    mystack.reserve(uplim+1);
    sp.reserve(uplim+1);
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

/*
attempt 1

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> nodes;
vector<ll> ans;
vector<int> parent;
vector<vector<int>> children;
vector<vector<int>> levels;
int n,root;
ll x;

void generate_levels()
{
    vector<int> v;
    v.push_back(root);
    levels.push_back(v);
    while(true)
    {
        auto &prevlevel=levels.back();
        vector<int> level;
        for(auto &node:prevlevel)
        {
            // cout<<"parent :"<<node<<'\n';
            for(auto &child:children[node])
            {
                // cout<<child<<'\n';
                level.push_back(child);
            }
        }
        if(level.size()==0){
            levels.pop_back();
            break;
        }
        levels.push_back(level);
    }
}

void find_root(){
    int node=1;
    while(parent[node]!=0)
    {
        node=parent[node];
    }
    root=node;
    generate_levels();
}

void solve()
{
    ll e1,e2;
    cin>>n>>x;
    nodes.reserve(n+1);
    parent.resize(n+1,0);
    ans.resize(n+1,0);
    levels.clear();
    children.resize(n+1);
    nodes[0]=0;
    for(int i=1;i<=n;i++) cin>>nodes[i];
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        parent[e2]=e1;
        children[e1].push_back(e2);
    }
    ll otans;
    find_root();
    for(auto it=levels.rbegin();it!=levels.rend();it++)
    {
        auto &level=*it;
        for(auto &node:level)
        {
            otans=nodes[node];
            for(auto &child:children[node])
            {
                otans+=ans[child];
            }
            ans[node]=max(-x,otans);
        }
    }
    cout<<ans[root]<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

*/

/*

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define con 100001

vector<ll> nodes(con);
vector<ll> ans(con);
vector<ll> parent(con);
vector<vector<ll>> children(con);
ll n,root;
ll x;

// void generate_levels()
// {
//     vector<int> v;
//     v.push_back(root);
//     levels.push_back(v);
//     while(true)
//     {
//         auto &prevlevel=levels.back();
//         vector<int> level;
//         for(auto &node:prevlevel)
//         {
//             // cout<<"parent :"<<node<<'\n';
//             for(auto &child:children[node])
//             {
//                 // cout<<child<<'\n';
//                 level.push_back(child);
//             }
//         }
//         if(level.size()==0){
//             levels.pop_back();
//             break;
//         }
//         levels.push_back(level);
//     }
// }

// void find_root(){
//     ll node=1;
//     while(parent[node]!=0)
//     {
//         node=parent[node];
//     }
//     root=node;
//     // generate_levels();
// }

ll findans(int node)
{
    if(ans[node]!=INT64_MIN) return ans[node];
    ll tans=nodes[node];
    for(auto &child:children[node])
    {
        tans+=findans(child);
    }
    ans[node]=max(-x,tans);
    return ans[node];
}
void pre()
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=0;
        children[i].clear();
    }
}


void solve()
{
    ll e1,e2;
    cin>>n>>x;
    pre();
    bool flag=true;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>nodes[i];
        sum+=nodes[i];
        if(nodes[i]<0) flag=false;
    }
    if(flag)
    {
        cout<<sum<<'\n';
        return ;
    }
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        parent[e2]=e1;
        children[e1].push_back(e2);
    }
    ll otans;
    // find_root();
    vector<int> randomindices(n);
    for(int i=0;i<n;i++) randomindices[i]=i+1;
    random_shuffle(randomindices.begin(),randomindices.end());
    for(int i=0;i<n;i++)
    {
        if(ans[randomindices[i]]==INT64_MIN) findans(randomindices[i]);
    }
    cout<<ans[root]<<'\n';
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define uplim 100001

ll values[uplim],ans[uplim];
int parent[uplim],nodelist[uplim],nodelistpos;

typedef struct tnode{
    int children[2];
    int childcount=0;
    int& operator [](int i){
        return children[i];
    }
    int add(int val){
        children[childcount++]=val;
    }
    int size(){
        return childcount;
    }
}nodes;

nodes children[uplim];
int n,root;
ll x;

ll findans(int node)
{
    if(ans[node]!=INT64_MIN) return ans[node];
    ll tans=values[node];
    for(auto &child:children[node])
    {
        tans+=findans(child);
    }
    ans[node]=max(-x,tans);
    return ans[node];
}


void solve()
{
    nodelistpos=0;
    int e1,e2;
    cin>>n>>x;
    ll myans=0;
    for(int i=1;i<=n;i++){
        cin>>values[i];
        parent[i]=0;
        children[i].childcount=0;
        ans[i]=INT64_MIN;
    }
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        parent[e2]=e1;
        children[e1].add(e2);
    }
    for(int i=1;i<=n;i++)
    {
        if(children[i].size()==0) childlist[childlistpos++]=i;
    }
    ll tans=0;
    int node;
    for(int i=0;i<childlistpos;i++)
    {
        node=childlist[i];
        tans=values[node];
        for(int child=0;child<children[node].size();i++)
        {
            tans+=ans[children[node][child]];
        }
        ans[node]=max(-x,tans);
    }
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define uplim 100001

ll values[uplim],ans[uplim];
int parent[uplim];
unordered_set<int> childlists[2];
vector<vector<int>> mymap;
typedef struct tnode{
    vector<int> childs;
    int& operator [](int i){
        return childs[i];
    }
    int add(int val){
        childs.push_back(val);
    }
    int size(){
        return childs.size();
    }
    void clear()
    {
        childs.clear();
    }
}nodes;

nodes children[uplim];
bool visited[uplim];
int n,root;
ll x;

void make_tree()
{
    int e1,e2;
    bool flag=true;
    for(int i=0;i<=n;i++) visited[i]=false,mymap[i].clear();
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        mymap[e1].push_back(e2);
        mymap[e2].push_back(e1);
    }
    queue<int> q;
    q.push(1);
    visited[1]=true;
    int node;
    while(!q.empty())
    {
        node=q.front();
        auto &childlist=mymap[node];
        for(auto &child:childlist)
        {
            if(!visited[child])
            {
                parent[child]=node;
                children[node].add(child);
                q.push(child);
                visited[child]=true;
            }
        }
        q.pop();
    }
}

void solve()
{
    int e1,e2;
    cin>>n>>x;
    ll myans=0;
    bool allpositive=false;
    parent[0]=0;
    children[0].clear();
    for(int i=1;i<=n;i++){
        cin>>values[i];
        myans+=values[i];
        if(values[i]<0) allpositive=false;
        parent[i]=0;
        children[i].clear();
        ans[i]=INT64_MIN;
    }
    make_tree();
    if(allpositive)
    {
        cout<<myans<<'\n';
        return;
    }
    childlists[0].clear();
    childlists[1].clear();
    for(int i=1;i<=n;i++)
    {
        if(children[i].size()==0) childlists[0].insert(i);
    }
    ll tans=0;
    bool flag=false,process=false,processnode;
    while(1)
    {
        auto &childlist=childlists[flag];
        auto &achildlist=childlists[!flag];
        achildlist.clear();
        for(auto &node:childlist)
        {
            processnode=true;
            tans=values[node];
            for(int child=0;child<children[node].size();child++)
            {
                if(ans[children[node][child]]==INT64_MIN) processnode=false;
                tans+=ans[children[node][child]];
            }
            if(!processnode)
            {
                achildlist.insert(node);
                continue;
            }
            ans[node]=max(-x,tans);
            if(parent[node]==0) process=true,root=node;
            else achildlist.insert(parent[node]);
        }
        if(flag) flag=false;
        else flag=true;
        if(process) break;
    }
    cout<<max(myans,ans[1])<<'\n';
}

int main()
{
    int t;
    cin>>t;
    childlists[0].reserve(uplim);
    childlists[1].reserve(uplim);
    mymap.reserve(uplim);
    while(t--)
    {
        solve();
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define uplim 100001

ll values[uplim],ans[uplim];
int parent[uplim];
unordered_set<int> childlists[2];
unordered_set<int> children[uplim];
bool visited[uplim];
int n,root;
ll x;

void make_tree()
{
    int e1,e2;
    bool flag=true;
    for(int i=0;i<=n;i++)
    {
        children[i].clear();
        parent[i]=0;
        ans[i]=INT64_MIN;
    }
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        children[e1].insert(e2);
        children[e2].insert(e1);
    }
    queue<int> q;
    q.push(1);
    int node;
    while(!q.empty())
    {
        node=q.front();
        auto &childlist=children[node];
        for(auto &child:childlist)
        {
            parent[child]=node;
            children[child].erase(node);
            q.push(child);
            visited[child]=true;
        }
        q.pop();
    }
}

void solve()
{
    int e1,e2;
    cin>>n>>x;
    ll myans=0;
    bool allpositive=false;
    for(int i=1;i<=n;i++){
        cin>>values[i];
        myans+=values[i];
        if(values[i]<0) allpositive=false;
    }
    make_tree();
    if(allpositive)
    {
        cout<<myans<<'\n';
        return;
    }
    childlists[0].clear();
    childlists[1].clear();
    for(int i=1;i<=n;i++)
    {
        if(children[i].size()==0) childlists[0].insert(i);
    }
    ll tans=0;
    bool flag=false,process=false,processnode;
    while(1)
    {
        auto &childlist=childlists[flag];
        auto &achildlist=childlists[!flag];
        achildlist.clear();
        for(auto &node:childlist)
        {
            processnode=true;
            tans=values[node];
            // for(int child=0;child<children[node].size();child++)
            for(auto &child:children[node])
            {
                if(ans[child]==INT64_MIN){
                    processnode=false;
                    break;
                }
                else tans+=ans[child];
            }
            if(!processnode)
            {
                achildlist.insert(node);
                continue;
            }
            ans[node]=max(-x,tans);
            if(parent[node]==0) process=true,root=node;
            else achildlist.insert(parent[node]);
        }
        if(flag) flag=false;
        else flag=true;
        if(process) break;
    }
    cout<<max(myans,ans[1])<<'\n';
}

int main()
{
    int t;
    cin>>t;
    childlists[0].reserve(uplim);
    childlists[1].reserve(uplim);
    while(t--)
    {
        solve();
    }
    return 0;
}
*/

/* 
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define uplim 100001

ll values[uplim],ans[uplim];
int parent[uplim];
set<int> children[uplim];
int visited[uplim];
int n,root,maxlevel;
ll x;
vector<int> levels[uplim];

void make_tree()
{
    int e1,e2;
    for(int i=0;i<=n;i++)
    {
        children[i].clear();
        parent[i]=0;
        ans[i]=INT64_MIN;
        visited[i]=0;
        levels[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        children[e1].insert(e2);
        children[e2].insert(e1);
    }
    queue<int> q;
    q.push(1);
    levels[1].push_back(1);
    int node,preslevel;
    visited[1]=1;
    maxlevel=1;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        preslevel=visited[node];
        maxlevel=max(maxlevel,preslevel);
        auto &childlist=children[node];
        for(auto &child:childlist)
        {
            parent[child]=node;
            children[child].erase(node);
            q.push(child);
            visited[child]=preslevel+1;
            levels[preslevel+1].push_back(child);
        }
    }
}

void solve()
{
    int e1,e2;
    cin>>n>>x;
    ll myans=0;
    bool allpositive=false;
    for(int i=1;i<=n;i++){
        cin>>values[i];
        myans+=values[i];
        if(values[i]<0) allpositive=false;
    }
    if(allpositive)
    {
        for(int i=1;i<n;i++) cin>>e1>>e2;
        cout<<myans<<'\n';
        return;
    }
    else make_tree();
    ll tmpans;
    for(int i=maxlevel;i>0;i--)
    {
        auto &preslevel=levels[i];
        for(auto &node:preslevel)
        {
            auto &childlist=children[node];
            tmpans=values[node];
            for(auto &child:childlist)
            {
                tmpans+=ans[child];
            }
            ans[node]=max(-x,tmpans);
        }
    }
    cout<<ans[1]<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
 */

/* 
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define uplim 100001

ll values[uplim],ans[uplim];
int parent[uplim];
set<int> children[uplim];
int visited[uplim];
int n,root,maxlevel;
ll x;
vector<int> levels[uplim];

void make_tree()
{
    int e1,e2;
    for(int i=0;i<=n;i++)
    {
        children[i].clear();
        parent[i]=0;
        ans[i]=INT64_MIN;
        visited[i]=0;
        levels[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        children[e1].insert(e2);
        children[e2].insert(e1);
    }
    queue<int> q;
    q.push(1);
    levels[1].push_back(1);
    int node,preslevel;
    visited[1]=1;
    maxlevel=1;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        preslevel=visited[node];
        maxlevel=max(maxlevel,preslevel);
        auto &childlist=children[node];
        for(auto &child:childlist)
        {
            parent[child]=node;
            children[child].erase(node);
            q.push(child);
            visited[child]=preslevel+1;
            levels[preslevel+1].push_back(child);
        }
    }
}

void solve()
{
    int e1,e2;
    cin>>n>>x;
    ll myans=0;
    bool allpositive=false;
    for(int i=1;i<=n;i++){
        cin>>values[i];
        myans+=values[i];
        if(values[i]<0) allpositive=false;
    }
    if(allpositive)
    {
        for(int i=1;i<n;i++) cin>>e1>>e2;
        cout<<myans<<'\n';
        return;
    }
    else make_tree();
    ll tmpans;
    for(int i=maxlevel;i>0;i--)
    {
        auto &preslevel=levels[i];
        for(auto &node:preslevel)
        {
            auto &childlist=children[node];
            tmpans=values[node];
            for(auto &child:childlist)
            {
                tmpans+=ans[child];
            }
            ans[node]=max(-x,tmpans);
        }
    }
    cout<<ans[1]<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
 */


/* 
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define uplim 100001

ll values[uplim],ans[uplim];
int parent[uplim];
vector<int> children[uplim];
int mystack[uplim],mystackpos,nodestopped[uplim];
int visited[uplim];
int n;
ll x;

void make_tree()
{
    int e1,e2;
    
}

void solve()
{
    int e1,e2;
    cin>>n>>x;
    ll myans=0;
    bool allpositive=false;
    for(int i=1;i<=n;i++){
        cin>>values[i];
        myans+=values[i];
        if(values[i]<0) allpositive=false;
    }
    if(allpositive)
    {
        for(int i=1;i<n;i++) cin>>e1>>e2;
        cout<<myans<<'\n';
        return;
    }
    for(int i=0;i<=n;i++)
    {
        parent[i]=0;
        ans[i]=INT64_MIN;
        visited[i]=0;
        cc[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        cc[e1]++;
        cc[e2]++;
        edges[i].first=e1;
        edges[i].second=e2;
    }
    for(int i=1;i<=n;i++)
    {
        children[i].
    }
    mystackpos=0;
    mystack[mystackpos]=1;
    while(mystackpos>=0)
    {
        for(auto &child:children[mystack[mystackpos]])
        {
            if(ans[child]==INT64_MIN)
            {
                parent[child]=
                mystack[++mystackpos]=child;
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
 */

/* 
#include<bits/stdc++.h>

using namespace std;

#define uplim 10001

typedef long long int ll;

ll x,ans[uplim],values[uplim],tans[uplim];
int parent[uplim];
int n;
vector<int> children[uplim];
vector<int> mystack;
vector<int> sp;

void construct_tree()
{
    int e1,e2;
    for(int i=1;i<n;i++)
    {
        cin>>e1>>e2;
        children[e1].push_back(e2);
        children[e2].push_back(e1);
    }
    // queue<int> q;
    // q.push(1);
    // int node;
    // while(!q.empty())
    // {
    //     node=q.front();
    //     q.pop();
    //     auto &childlist=children[node];
    //     for(auto &child:childlist)
    //     {
    //         parent[child]=node;
    //         if(child!=node) q.push(child);
    //     }
    // }
}

void solve()
{
    cin>>n>>x;
    assert(n<uplim);  
    for(int i=1;i<=n;i++){
        cin>>values[i]; 
        tans[i]=values[i]; 
        parent[i]=-1;
        ans[i]=INT64_MIN;
        children[i].clear();
    }
    construct_tree();
    mystack.push_back(1);
    sp.push_back(0);
    parent[1]=0;
    int node,child;
    while(mystack.size())
    {
        node=mystack.back();
        auto &toprocess=sp.back();
        auto &childrenlist=children[node];
        for(;toprocess<childrenlist.size();toprocess++)
        {
            if((child=childrenlist[toprocess]))
            {
                if(parent[child]==-1)
                {
                    parent[child]=node;
                }
                if(child==parent[node]) continue;
                if(ans[child]==INT64_MIN)
                {
                    mystack.push_back(child);
                    sp.push_back(0);
                    break;
                }
                else
                {
                    tans[node]+=ans[child];
                }
            }
        }
        if(toprocess==childrenlist.size())
        {
            ans[node]=max(-x,tans[node]);
            mystack.pop_back();
            sp.pop_back();
        }
    }
    cout<<ans[1]<<'\n';
}

int main()
{
    int t;
    mystack.reserve(uplim+1);
    sp.reserve(uplim+1);
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
 */
#include<bits/stdc++.h>
using namespace std;

int n,reqop,l;
float damage;
string code;

float calcDamage(string s)
{
    float curpo=1,curdamage=0;
    for(auto &ch:s)
    {
        if(ch=='M') curpo*=3;
        else if(ch=='K') curdamage+=curpo;
        else
        {
            if(curpo>=2) curpo/=2;
        }
    }
    return curdamage;
}
void bfs()
{
    string cur;
    queue<string> q;
    map<string,int> visited;
    q.push(code);
    damage=calcDamage(code);
    if(damage<=n)
    {
        reqop=1;
        return;
    }
    int cursteps=1;
    visited[code]=1;
    l=code.size();
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        cursteps=visited[cur];
        for(int i=1;i<l;i++)
        {
            if(cur[i]==cur[i-1]) continue;
            swap(cur[i],cur[i-1]);
            if(visited.find(cur)==visited.end()&&cursteps<l)
            {
                auto tmp=calcDamage(cur);
                q.push(cur);
                visited[cur]=cursteps+1;
                if(tmp<damage) damage=tmp,reqop=cursteps+1; 
                if(damage<=n)
                {
                    //cout<<damage<<' '<<cur<<'\n';
                    return;
                }
            }
            swap(cur[i],cur[i-1]);
        }
    }

}

int main()
{
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>n>>code;
        reqop=0;
        bfs();
        if(damage<=n)
        {
            cout<<reqop-1<<'\n';
        }
        else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
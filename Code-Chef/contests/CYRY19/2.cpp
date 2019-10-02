#include<bits/stdc++.h>

using namespace std;

typedef struct{
int pos,coding_skill,phys_fitness,comm_skill;
}player;

bool cmp(player &p,player &q)
{
    if(p.coding_skill==q.coding_skill)
    {
        if(p.phys_fitness==q.phys_fitness)
        {
            if(p.comm_skill==q.comm_skill)
            {
                return p.pos>q.pos;
            }
            return p.comm_skill>q.comm_skill;
        }
        return p.phys_fitness>q.phys_fitness;
    }
    return p.coding_skill>q.coding_skill;
}

int main()
{
    int n;
    cin>>n;
    vector<player> v(n);
    for(int i=0;i<n;i++) v[i].pos=i+1,cin>>v[i].coding_skill;
    for(int i=0;i<n;i++) cin>>v[i].phys_fitness;
    for(int i=0;i<n;i++) cin>>v[i].comm_skill;
    sort(v.begin(),v.end(),cmp);
    for(auto &p:v)
    {
        cout<<p.pos<<' '<<p.coding_skill<<' '<<p.phys_fitness<<' '<<p.comm_skill<<'\n';
    }
    return 0;
}
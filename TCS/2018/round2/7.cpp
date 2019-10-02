#include<bits/stdc++.h>
using namespace std;
int n,m,b;
int mat[11][11];
vector<string> party={"","AAA","BBB","Others"};
int win_party,seats;
bool Majority;
void get_data()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++) cin>>mat[i][j];
    }
}
void find_b()
{
    int prod=m*n,p;
    b=__gcd(m,n);
    if(b<m&&b<n) return;
    p=min(m,n);
    p--;
    while(p>1)
    {
        if((m%p)==0&&(n%p)==0)
        {
            b=p;
            return;
        }
        p--;
    }
    //shouldn't reach here, but just in case
    b=p;
}
vector<int> findmax(int row_begin,int col_begin)
{
    int row_end=row_begin+b;
    int col_end=col_begin+b;
    map<int,int> o;
    for(int i=row_begin;i<row_end;i++) for(int j=col_begin;j<col_end;j++) o[mat[i][j]]++;
    //if 2 or more parties have equal strength
    vector<pair<int,int>> res;
    vector<int> fres;
    for(auto &mpair:o)
    {
        res.push_back(mpair);
    }
    sort(res.begin(),res.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second; });
    int presparty,presvotes,majorityvotescount=0;
    auto it=res.begin();
    tie(presparty,presvotes)=*it;
    for(auto &mpair:res)
    {
        if(mpair.second>=presvotes) fres.push_back(mpair.first);
    }
    return fres;
}
void process_data()
{
    map<int,int> seats_won;
    for(int i=1;i<m;i+=b)
    {
        for(int j=1;j<n;j+=b)
        {
            auto v=findmax(i,j);
            for(auto &pa:v) seats_won[pa]++;
        }
    }
    vector<pair<int,int>> res,fres;
    for(auto &mpair:seats_won)
    {
        res.push_back(mpair);
    }
    sort(res.begin(),res.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second; });
    int presparty,presvotes,majorityvotescount=0;
    auto it=res.begin();
    tie(presparty,presvotes)=*it;
    for(auto &mpair:res)
    {
        if(mpair.second>=presvotes) majorityvotescount++;
    }
    if(majorityvotescount==1)
    {
        Majority=true,win_party=presparty,seats=presvotes;
    } 
}

void do_trading()
{
    int t,x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>z;
        mat[x][y]=z;
    }
}

int main(int argc, char const *argv[])
{
    get_data();
    find_b();
    process_data();
    if(Majority)
    {
        cout<<"Initial Majority Party:Seats = "<<party[win_party]<<':'<<seats<<'\n';
    }
    else cout<<"No Majority\n";
    do_trading();
    Majority=false;
    process_data();
    if(Majority){
        cout<<"Party Won Party:Seats = "<<party[win_party]<<':'<<seats;
    }
    else cout<<"No Majority\n";
    return 0;
}
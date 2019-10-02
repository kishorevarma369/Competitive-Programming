#include<bits/stdc++.h>
using namespace std;
int n,m,b;
int mat[11][11];
map<int,string> party={{0,""},{1,"AAA"},{2,"BBB"},{3,"Others"}};
int win_party,seats;

void find_b()
{
    int prod=m*n,p;
    b=__gcd(m,n);
    if(b<m&&b<n) return;
    if(m>n) p=n;
    else p=m;
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
    b=p;
}

void process_data()
{
    map<int,int> seats_won;
    for(int i=1;i<m;i+=b)
    {
        for(int j=1;j<n;j+=b)
        {
            int row_begin=i,col_begin=j;
            map<int,int> regional;    
            for(int k=row_begin;k<row_begin+b;k++) for(int l=col_begin;l<col_begin+b;l++) regional[mat[k][l]]++;
            auto tmp = max_element(regional.begin(), regional.end(),
            [](const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.second < p2.second; });
            auto mymax=tmp->second;
            int maxcount=0;
            for(auto &p:regional)
            {
                if(p.second==mymax) maxcount++;
            }
            if(maxcount==1) seats_won[tmp->first]++;
        }
    }
    auto tmp = max_element(seats_won.begin(), seats_won.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });
    auto mymax=tmp->second;
    int maxcount=0;
    for(auto &p:seats_won)
    {
        if(p.second==mymax) maxcount++;
    }
    if(maxcount==1) win_party=tmp->first,seats=mymax;
    else win_party=0,seats=0;
}

int main(int argc, char const *argv[])
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++) cin>>mat[i][j];
    }
    find_b();
    process_data();
    cout<<"Initial Majority Party:Seats = ";
    if(win_party) cout<<party[win_party]<<':'<<seats<<'\n';
    else cout<<"No Majority\n";
    int t,x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>z;
        mat[x][y]=z;
    }
    process_data();
    cout<<"Party Won Party:Seats = ";
    if(win_party) cout<<party[win_party]<<':'<<seats<<'\n';
    else cout<<"No Majority\n";
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n,m,b;
int mat[11][11];

vector<string> party={"","AAA","BBB","Others"};
int win_party,seats;

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
    int m,n;
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

int findmax(int row_begin,int col_begin)
{
    int row_end=row_begin+b;
    int col_end=col_begin+b;
    map<int,int> o;
    for(int i=row_begin;i<row_end;i++) for(int j=col_begin;j<col_end;j++) o[mat[i][j]]++;
    auto x = std::max_element(o.begin(), o.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });
    return (*x).first;
}

void process_data()
{
    map<int,int> seats_won;
    for(int i=1;i<m;i+=b)
    {
        for(int j=1;j<n;j+=b)
        {
            seats_won[findmax(i,j)]++;
        }
    }
    auto x = std::max_element(seats_won.begin(), seats_won.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });
    win_party=(*x).first;
    seats=(*x).second;
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
    find_b();
    /*get_data();
    find_b();
    process_data();
    cout<<"Initial Majority Party:Seats = "<<party[win_party]<<':'<<seats<<'\n';
    do_trading();
    process_data();
    cout<<"Party Win Party:Seats = "<<party[win_party]<<':'<<seats;
    */
    return 0;
}

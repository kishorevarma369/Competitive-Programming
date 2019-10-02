/*
kishorevarma
in.kishorevarma@gmail.com
website:kishorevarma.net

why codevita why -> already given this question in round 1 :(
*/

#include<bits/stdc++.h>
using namespace std;
vector<string> party={"","AAA","BBB","Others"};
int n,m,b,win_party,seats;
int matrix[15][15];

int cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; 
}

int maxfinder(int row_begin,int col_begin)
{
    map<int,int> o;
    int row_end=row_begin+b;
    int col_end=col_begin+b;
    for(int i=row_begin;i<row_end;i++) for(int j=col_begin;j<col_end;j++) o[matrix[i][j]]++;
    auto x = max_element(o.begin(), o.end(),cmp);
    return x->first;
}

void process()
{
    map<int,int> seats_won;
    for(int i=1;i<m;i+=b)
    {
        for(int j=1;j<n;j+=b)
        {
            seats_won[maxfinder(i,j)]++;
        }
    }
    auto x = max_element(seats_won.begin(), seats_won.end(),cmp);
    win_party=x->first;
    seats=x->second;
}

int main(int argc, char const *argv[])
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++) cin>>matrix[i][j];
    }
    int prod=m*n,p;
    b=__gcd(m,n);
    if(!(b<m&&b<n))
    {
        p=min(m,n);
        p--;
        while(p>1)
        {
            if((m%p)==0&&(n%p)==0)
            {
                b=p;
                goto done_finding_b;
            }
            p--;
        }
    }
    done_finding_b:
    process();
    cout<<"Initial Majority Party:Seats = "<<party[win_party]<<':'<<seats<<'\n';
    int t,x,y,z;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>z;
        matrix[x][y]=z;
    }
    process();
    cout<<"Party Won Party:Seats = "<<party[win_party]<<':'<<seats;
    return 0;
}
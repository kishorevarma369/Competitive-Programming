#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int m,n;
int ap[]={1,1,0,-1,-1,-1,0,1};
int bp[]={0,1,1,0,1,-1,-1,-1};

bool isvalid(int i,int j)
{
    if(i==0&&j==0) return false;
    if(i<0||j<0||i>=m||j>=n) return false;
    return true;
}

int calc(vector<vector<int>> &a,int i,int j)
{
    if(i==0&&j==0) return 0;
    int qvalue=0;
    for(int k=0;k<8;k++)
    {
        if(isvalid(i+ap[k],j+bp[k])) qvalue+=a[i+ap[k]][j+bp[k]];
    }
    return qvalue;
}

int minsteps(int i,int j)
{
    int p=min(i,j);
    p+=abs(i-j);
    return p;
}

int main(int argc, char const *argv[])
{
    int i,j,mymax=0,temp,x,y;
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n)),q(m,vector<int>(n));
    vector<tuple<int,int,int>> finqual;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++) cin>>a[i][j];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                q[i][j]==0;
                continue;
            }
            q[i][j]=calc(a,i,j);
            temp=max(mymax,q[i][j]);
            if(temp>mymax)
            {
                finqual.clear();
                finqual.push_back(make_tuple(i,j,minsteps(i,j)));
                mymax=temp;
            }
            else if(q[i][j]==mymax&&q[i][j]!=0)
            {
                auto z=make_tuple(i,j,minsteps(i,j));
                finqual.push_back(z);
            } 
        }
    }
    if(finqual.empty()) cout<<"No suitable girl found";
    else
    {
        temp=finqual.size();
        if(temp==1)
        {
            tie(x,y,temp)=finqual[0];
            cout<<x+1<<':'<<y+1<<':'<<mymax;
        }
        else
        {
            sort(finqual.begin(),finqual.end(),[](tuple<int,int,int> p,tuple<int,int,int> q){return get<2>(p) < get<2>(q);});
            /*cout<<'\n';
            for(auto i:finqual)
            {
                cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<get<2>(i)<<'\n'; 
            }*/
            if(get<2>(finqual[0]) == get<2>(finqual[1]))
            {
                cout<<"Polygamy not allowed";
            }
            else
            {
                tie(x,y,temp)=finqual[0];
                cout<<x+1<<':'<<y+1<<':'<<mymax;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int ax[]={1,0,-1,0};
int by[]={0,1,0,-1};

vector<vector<int>> v;

int m,n;

bool isvalid(int x,int y)
{
    if(x>=0&&x<m&&y>=0&&y<n) return true;
    return false;
}

void blast()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==2)
            {
                v[i][j]=0;
                for(int k=0;k<4;k++)
                {
                    if(isvalid(i+ax[k],j+by[k]))
                    {
                        if(v[i+ax[k]][j+by[k]]==1) v[i+ax[k]][j+by[k]]=0;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==1)
            {
                v[i][j]=2;
            }
        }
    }
}

void setall()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==0) v[i][j]=1;
        }
    }
}

void onesecond(){
}

void print(vector<vector<int>> &v)
{
    // cout<<'\n';
    for(auto &i:v)
    {
        for(auto &j:i)
        {
            if(j==0) cout<<'.';
            else cout<<'O';
        }
        cout<<'\n';
    }
    // cout<<'\n';
}

void print1()
{
    cout<<'\n';
    for(auto &i:v)
    {
        for(auto &j:i)
        {
            cout<<j;
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main(int argc, char const *argv[])
{
    int k,p=0;
    cin>>m>>n>>k;
    v.resize(m);
    string s;
    for(int i=0;i<m;i++)
    {
        cin>>s;
        v[i].resize(n);
        for(int j=0;j<n;j++)
        {
            if(s[j]=='O') v[i][j]=2;
            else v[i][j]=0;
        }
    }
    map<vector<vector<int>>,int> myset;
    map<int,vector<vector<int>>> index;
    if(k%2==0)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) cout<<'O';
            cout<<'\n';
        }
        return 0;
    }
    int pos=1,targetpos=1;
    index[pos]=v;
    myset[v]=pos++;
    while(1)
    {
        setall();
        blast();
        auto it=myset.find(v);
        if(it==myset.end())
        {
            index[pos]=v;
            myset[v]=pos++;
        }
        else{
            targetpos=it->second;
            break;
        } 
    }
    // for(auto &a:myset)
    // {
    //     auto my=a.first;
    //     for(auto &row:my)
    //     {
    //         for(auto &el:row) cout<<el;
    //         cout<<'\n';
    //     }
    // }
    int cycle_size=pos-targetpos;
    k=k/2+1;
    if(k>=targetpos)
    {
        k-=targetpos;
        k=k%cycle_size+targetpos;

    }
    auto ans=index[k];
    print(ans);
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;
string s;
ll sz,ans;
vector<int> v[26];
ll cache[1005][1005];
ll pal[1005][1005],toleft[1005][1005],toright[1005][1005];

void transpose()
{
    for(int i=0;i<sz;i++)
    {
        for(int j=i+1;j<sz;j++)
        {
            swap(pal[j][i],pal[i][j]);
        }
    }
}

void pre()
{
    for(int j=1;j<=sz;j++)
    {
        for(int i=0;i<=sz-j;i++)
        {
            if(j<=2&&s[i]==s[i+j-1]){
                pal[i][i+j-1]=1;
            }
            else if(s[i]==s[i+j-1])
            {
                pal[i][i+j-1]=pal[i+1][i+j-2];
            }
        }
    }
    for(int i=0;i<sz;i++)
    {
        toleft[i][0]=pal[i][0];
        for(int j=1;j<sz;j++) toleft[i][j]=toleft[i][j-1]+pal[i][j];
    }
    transpose();
    for(int i=0;i<sz;i++)
    {
        toright[i][sz-1]=pal[i][sz-1];
        for(int j=sz-2;j>=0;j--) toright[i][j]=toright[i][j+1]+pal[i][j];
    }
    // for(int i=0;i<sz;i++)
    // {
    //     for(int j=0;j<sz;j++) cout<<pal[i][j]<<' ';
    //     cout<<'\n';
    // }
}

int f(int i,int j)
{
    if(!(i>=0&&i<sz&&j>=0&&j<sz)) return 0;
    if(i>=j) return 0;
    // if(i==j) return 1;
    if(cache[i][j]!=INT_MIN) return cache[i][j];
    if(s[i]!=s[j]) return 0;
    //1+no of pallind between i and j from left and toright
    // int x=toleft[i][j]-((i-1>=0)?toleft[i][i-1]:0),y=toright[i][i]-((j+1<sz)?toright[i][j+1]:0);
    // int x=toleft[i+1][j-1]-toleft[i+1][i],y=toright[i+1][i+1]-toright[i+1][j];
    if(j-i>1){
    ll x=toleft[i+1][j-1]-toleft[i+1][i],y=toright[j-1][i+1]-toright[j-1][j];
    cache[i][j]=1+x+y+f(i+1,j-1);
    }
    else cache[i][j]=1;
    return cache[i][j];
}

void find_ans()
{
    for(int i=0;i<26;i++)
    {
        auto &poslist=v[i];
        for(int j=0;j<poslist.size();j++)
        {
            for(int k=j+1;k<poslist.size();k++)
            {
                ans+=f(poslist[j],poslist[k]);
            }
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    cin>>s;
    sz=s.size();
    pre();
    for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) cache[i][j]=INT_MIN;
    for(int i=0;i<sz;i++) v[s[i]-'a'].push_back(i);
    find_ans();
    return 0;
}
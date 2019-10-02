#include<bits/stdc++.h>

using namespace std;

int a,b;

vector<int> v;

int find_parent(int x)
{
    if(v[x]==x) return x;
    return find_parent(v[x]);
}

void make()
{
    int x=find_parent(a);
    int y=find_parent(b);
    if(x!=y) v[a]=y; 
}

int main(int argc, char const *argv[])
{
    int n,p;
    cin>>n>>p;
    v.resize(n);
    for(int i=0;i<n;i++) v[i]=i;
    for(int i=0;i<p;i++)
    {
        cin>>a>>b;
        make();
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,d,cou=0,i,j,median_pos,int_median;
    cin>>n>>d;
    vector<int> v(n);
    for(i=0;i<n;i++) cin>>v[i];
    multiset<int> myset;
    for(i=0;i<d;i++) myset.insert(v[i]);
    j=0;
    auto it=myset.begin();
    median_pos=d/2;
    if(d&1)
    {
        for(;i<n;i++,j++)
        {
            it=myset.begin();
            advance(it,median_pos);
            int_median=*it;
            if(v[i]>=2*int_median) cou++;
            myset.erase(v[j]);
            myset.insert(v[i]);
            
        }
    }
    else
    {
        for(;i<n;i++,j++)
        {
            it=myset.begin();
            advance(it,median_pos);
            int_median=*it;
            advance(it,-1);
            int_median+=*it;
            if(v[i]>=int_median) cou++;
            myset.erase(v[j]);
            myset.insert(v[i]);
            
        }
    }
    cout<<cou<<'\n';
    return 0;
}

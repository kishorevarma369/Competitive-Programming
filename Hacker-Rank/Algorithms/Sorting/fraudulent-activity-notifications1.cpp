#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,d,cou=0,i,j,median_pos,int_median,median_beg,median_end,tmb,tme;
    cin>>n>>d;
    vector<int> v(n);
    for(i=0;i<n;i++) cin>>v[i];
    map<int,int> mymap;
    for(i=0;i<d;i++) mymap[v[i]]++;
    j=0;
    auto it=mymap.begin();
    median_pos=d/2+1;
    median_beg=0;
    for(auto &p:mymap)
    {
        j+=p.second;
        if(j>=median_pos)
        {
            median_beg=j-p.second;
            median_end=j-1;
            int_median=p.first;
            break;
        }
    }
    median_pos--;
    j=0;
    for(;i<n;i++,j++)
    {
        if(v[i]>=2*int_median) cou++;
        tmb=median_beg;
        tme=median_end;
        if(v[j]<int_median)
        {
            if(v[i]==int_median) median_beg--;
            else if(v[i]>int_median)
            {
                median_beg--;
                median_end--;
            }
        }
        else if(v[j]==int_median)
        {
            if(v[i]<int_median)
            {
                median_beg++;
            }
            else if(v[i]>int_median)
            {
                median_end--;
            }
        }
        else
        {
            if(v[i]<=int_median)
            {
                if(v[i]!=int_median) median_beg++;
                median_end++;
            }
        }
        it=mymap.find(v[j]);
        if(it->second==1) mymap.erase(it);
        else it->second-=1;
        mymap[i]++;
        if((median_beg>median_end)||!(median_beg<=d&&median_end>=d))
        {
            for(auto &p:mymap)
            {
                j+=p.second;
                if(j>=median_pos)
                {
                    median_beg=j-p.second;
                    median_end=j-1;
                    int_median=p.first;
                    break;
                }
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

void print(vector<pair<int,int>> &v)
{
    for(auto &pr:v) printf("(%d,%d) , ",pr.first,pr.second);
    printf("\n");
}

int deleteProducts(vector<int> ids,int m)
{
    map<int,int> mymap;
    for(auto id:ids) mymap[id]++;
    vector<pair<int,int>> finpairs;
    for(auto &pr:mymap)
    {
        finpairs.push_back({pr.second,pr.first});
    }
    sort(finpairs.begin(),finpairs.end());
    int no_of_possible=finpairs.size(),beg=0;
    while(m>0&&beg<finpairs.size())
    {
        auto &tmp=finpairs[beg];
        if(tmp.first<=m)
        {
            no_of_possible--;
            m=m-tmp.first;
            tmp.first=0;
            beg++;
        }
        else break;
    }
    return no_of_possible;
}

int main()
{
    vector<int> ids={1,1,2,1,2,3,1};
    cout<<deleteProducts(ids,1);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
//awesome question we should also consider descending order , amazing
struct my
{
    int val;
    int pos;
};

typedef struct my mys;

bool com(mys &b,mys &c)
{
    return b.val<c.val;
}

int main() {
    int n;
    cin >> n;
    vector<mys> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i].val;
        arr[arr_i].pos=arr_i;
    }
    sort(arr.begin(),arr.end(),com);
    int co=0,i,mi;
    map<int,int> mymap,visited;
    for(i=0;i<n;i++)
    {
        if(arr[i].pos!=i)
        {
            mymap[arr[i].pos]=i;
        }
    }
    for(auto &j:mymap)
    {
        if(visited[j.first]) continue;
        i=j.first;
        while(!visited[i])
        {
            visited[i]=1;
            i=mymap[i];
            co++;
        }
        co--;
    }
    mi=co;
    co=0;
    mymap.clear();
    visited.clear();
    reverse(arr.begin(),arr.end());
    for(i=0;i<n;i++)
    {
        if(arr[i].pos!=i)
        {
            mymap[arr[i].pos]=i;
        }
    }
    for(auto &j:mymap)
    {
        if(visited[j.first]) continue;
        i=j.first;
        while(!visited[i])
        {
            visited[i]=1;
            i=mymap[i];
            co++;
        }
        co--;
    }
    mi=min(mi,co);
    cout<<mi<<'\n';
    return 0;
}

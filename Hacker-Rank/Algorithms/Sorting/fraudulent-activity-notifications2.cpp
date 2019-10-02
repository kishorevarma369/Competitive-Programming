#include<bits/stdc++.h>

using namespace std;

int arr[201],n,p,d,mymedian;

void find_median()
{
    int val=0;
    for(int i=0;i<201;i++)
    {
        val+=arr[i];
        if(val>=(d+1))
        {
            mymedian=i;
            break;
        }
    } 
}

void find_median1()
{
    int i=0,val=0;
    while(val<d)
    {
        val+=arr[i];
        i++;
    }
    i--;
    mymedian=i;

    if(val>d) mymedian+=i;
    else{
        i++;
        while(!arr[i]) i++;
        mymedian+=i;
    }
}


int main(int argc, char const *argv[])
{
    int cou=0,i,j,median_pos,tmb,tme;
    cin>>n>>p;
    vector<int> v(n);
    for(i=0;i<n;i++) cin>>v[i];
    for(i=0;i<p;i++) arr[v[i]]++;
    j=0;
    d=p/2;
    if(p&1)
    {
        for(;i<n;i++,j++)
        {
            find_median();
            if(v[i]>=2*mymedian) cou++;
            arr[v[j]]--;
            arr[v[i]]++;
        }
    }
    else
    {
        for(;i<n;i++,j++)
        {
            find_median1();
            if(v[i]>=mymedian) cou++;
            arr[v[j]]--;
            arr[v[i]]++;
        }
    }
    cout<<cou<<'\n';
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int pi,pj,v;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++){
            cin>>v;
            if(v)
            {
                pi=i;
                pj=j;
            }
        } 
    }
    v=abs(pi-2)+abs(pj-2);
    cout<<v<<'\n';
    return 0;
}
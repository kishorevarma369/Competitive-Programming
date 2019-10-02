#include<bits/stdc++.h>

using namespace std;

#define mycon 100001

int main()
{
    int t;
    int a,b,n,i,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<vector<int>> v(mycon);
        for(i=1;i<=n;i++) 
        {
            cin>>a;
            v[a].push_back(i);
        }
        for(i=0;i<mycon;i++)
        {
            if(int(v[i].size())>1)
            {
                cnt=0;
                for(auto &p:v[i])
                {
                    if(int(v[p].size())>0) cnt++;
                    if(cnt>1) goto ans;
                } 
            }
        }
        cout<<"Poor Chef\n";
        continue;
        ans:
        cout<<"Truly Happy\n";
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int arr[30002];

int find_ans(int val)
{
    stringstream ss;
    ss<<val;
    string s;
    ss>>s;
    char prev=s.back();
    int tval=1,ans=0;
    for(int i=int(s.size())-1;i>=0;i--)
    {
        if(s[i]!=prev)
        {
            ans+=(prev-'0')*tval/10;
            prev=s[i];
        }
        tval*=10;
    }
    ans+=((prev-'0')*tval/10);
    // printf("%d = %d\n",val,ans);
    return ans;
}

int main()
{  
    for(int i=1;i<=30000;i++)
    {
        // cout<<arr[i]<<'\n';
        arr[i]=i-find_ans(i)+arr[i-1];
    }
    // for(int i=0;i<99;i++)   printf("%d = %d\n",i,arr[i]);
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("%d to %d = %d\n",i*100,i*100+99,arr[i*100+99]-arr[(i*100-1)>=0?(i*100-1):0]);
        
    // }
    // for (int i = 1100; i < 1200; i++)
    // {
    //     printf("%d to %d = %d\n",i*10,i*10+9,arr[i*10+9]-arr[(i*10-1)>=0?(i*10-1):0]);
    // }
    // for (int i = 0; i < 20; i++)
    // {
    //     int k=arr[i*1000+999]-arr[(i*1000-1)>=0?(i*1000-1):0];
    //     printf("%d to %d = %d ,%d\n",i*1000,i*1000+999,k,2*k);
        
    // }
    int k;
    // cout<<(97*98/2-8*9/2-(arr[97]-arr[8]))<<'\n';
    // for(int i=27;i<=273;i++)
    // {
    //     k=arr[i]-arr[i-1];
    //     if(k!=0)
    //     {
    //         printf("%d - %d\n",i,k);
    //     }
    // }
    int val1,val2;
    while(true)
    {
        cin>>val1>>val2;
        cout<<arr[val2]-arr[val1-1];
    }
    return 0;
}
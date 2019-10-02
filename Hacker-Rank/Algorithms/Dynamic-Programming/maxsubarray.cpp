#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
int arr[100000];
int n;

void fun()
{
    ll sum_till_now=arr[0],max_sum=arr[0],susq=0;
    for(int i=1;i<n;i++)
    {
        if(sum_till_now<0)
        {
            sum_till_now=0;
        }
        sum_till_now+=arr[i];
        if(sum_till_now>max_sum) max_sum=sum_till_now;
    }
    int mymax=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0) susq+=arr[i];
        mymax=max(mymax,arr[i]);
    }
    if(susq==0)
    {
        if(mymax!=INT_MIN)
        {
            susq=mymax;
        }
    } 
    cout<<max_sum<<' '<<susq<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        fun();
    }
    return 0;
}
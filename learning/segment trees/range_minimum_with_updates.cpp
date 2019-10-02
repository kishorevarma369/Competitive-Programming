#include<bits/stdc++.h>

using namespace std;

int segment_tree[200005];
int arr[100001];
#define x 500

void construct_segment_tree(int n){
    for(int i=n-1;i>0;i--)
    {
        segment_tree[i]=min(segment_tree[2*i],segment_tree[2*i+1]);
    }
}

int query(int l,int r,int n)
{
    l+=n;
    r+=n+1;
    int min_val=INT_MAX;
    while(l<r)
    {
        if(l&1) min_val=min(min_val,segment_tree[l]),l++;
        if(r&1) r--,min_val=min(min_val,segment_tree[r]);
        l/=2;
        r/=2;
    }
    return min_val;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%x+1;
        segment_tree[n+i]=arr[i];
        printf("%d ",arr[i]);
    }
    putchar('\n');
    construct_segment_tree(n);
    int q,l,r;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        if(l>=0&&l<n&&r>=0&&r<n&&l<=r)
        {
            cout<<query(l,r,n)<<'\n';
        }
    }
    return 0;
}
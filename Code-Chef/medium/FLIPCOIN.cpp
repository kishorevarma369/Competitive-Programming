#include<bits/stdc++.h>

using namespace std;

pair<int,int> segment_tree[265432];
bool lazy[265432];

int n,N;

void modify(int node)
{
    auto t=segment_tree[node];
    segment_tree[node]={t.second,t.first};
    lazy[node]=false;
    if(node<N)//not a leaf node
    {
        lazy[node<<1]^=1;
        lazy[node<<1|1]^=1;
    }
}

void update(int node)
{
    int l=node<<1;
    int r=l+1;
    segment_tree[node].first=segment_tree[l].first+segment_tree[r].first;
    segment_tree[node].second=segment_tree[l].second+segment_tree[r].second;
}


int query(int l,int r,int beg,int end,int node)
{
    if(r<beg||l>end)
    {
        return 0;
    }
    if(lazy[node]) modify(node);
    if(l<=beg&&end<=r){
        return segment_tree[node].first;
    }
    int mid=(beg+end)/2;
    return query(l,r,beg,mid,2*node)+query(l,r,mid+1,end,2*node+1);
}

void flip(int l,int r,int beg,int end,int node)
{
    if(r<beg||l>end)
    {
        return ;
    }
    if(l<=beg&&end<=r){
        if(lazy[node]){
            lazy[node]=false;
        }
        else{
            modify(node);
        }
        return;
    }
    int mid=(beg+end)/2;
    flip(l,r,beg,mid,2*node);
    flip(l,r,mid+1,end,2*node+1);
    update(node);
}

int nearest_power_of_two(int n)
{
    int val=0;
    int count=__builtin_popcount(n);
    if(count==1) return n<<1;
    while(n)
    {
        n>>=1;
        val++;
    }
    return 1<<val;
}

void build()
{
    int end=n+N,node=N-1;
    for(int i=N;i<end;i++) segment_tree[i]={0,1};
    while(node>=1)
    {
        update(node);
        node--;
    }
}

bool ispoweroftwo(int n){
    if(n!=0&&(n&(n-1))==0) return true;
    return false;
}

void print_segment_tree()
{
    printf("-------------------------------------------------");
    int end=2*N,i=1;
    while(i<end)
    {
        if(ispoweroftwo(i)) printf("\n");
        printf("\t(%d,%d,status=%d)\t",segment_tree[i].first,segment_tree[i].second,lazy[i]);
        i++;
    }
    printf("-------------------------------------------------");
}

int main()
{
    int q,t,l,r;
    cin>>n>>q;
    N=nearest_power_of_two(n);
    assert(265432>=2*N);
    build();
    print_segment_tree();
    while(q--)
    {
        cin>>t>>l>>r;
        if(t)
        {
            cout<<query(l,r,0,N-1,1)<<'\n';
        }
        else{
            //flip coins in range
            flip(l,r,0,N-1,1);
        }
        print_segment_tree();
    }
    return 0;
}
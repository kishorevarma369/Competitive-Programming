#include<bits/stdc++.h>

using namespace std;

map<int,int> arr[266666];
int primes[1000001];

#define debug

int n,N,l,r,ans=0,x,y;
//assume  i have primes then
int nearest_power2(int val)
{
    assert(val>0);
    if(val&(val-1)==0) return val;
    int c=0;
    while(val)
    {
        val>>=1;
        c++;
    }
    return 1<<c;
}

void primegen()
{
    for(int i=2;i<=1000000;i+=2) primes[i]=2;
    for(int i=3;i<=1000000;i+=2) if(primes[i]==0) primes[i]=i;
    for(int i=3;i<=1000000;i+=2)
    {
        if(primes[i]==i)
        {
            for(int j=i+i;j<=1000000;j+=i) if(primes[j]==j) primes[j]=i;
        }
    }
}

void printTree()
{
    int k=n+N-1,i;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        auto &factlist=arr[i];
        printf("Node %d:{ ",i);
        for(auto &node:factlist)
        {
            printf("( %d,%d )",node.first,node.second);
        }
        printf(" }\n");
        i=2*i;
        if(i<=k) q.push(i++);
        if(i<=k) q.push(i);
    }
}

void build()
{
    int parent=n+N-1;
    for(;parent>0;parent--)
    {
        auto &child1=arr[parent<<1];
        auto &child2=arr[(parent<<1)|1];
        auto &parentlist=arr[parent];
        for(auto &primefactor:child1)
        {
            parentlist[primefactor.first]+=primefactor.second;
        }
        for(auto &primefactor:child2)
        {
            parentlist[primefactor.first]+=primefactor.second;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #ifdef debug
        auto start_time=clock();
    #endif
    primegen();
    int q,val;
    cin>>N;
    n=nearest_power2(N);
    int j=n,t1,t2;
    for(int i=0;i<N;i++)
    {
        cin>>val;
        auto &primelist=arr[j];
        while(val>1){
            t1=primes[val];
            primelist[t1]++;
            val=val/t1;
            auto &it=*primelist.find(t1);
            while((val%t1)==0)
            {
                val/=t1;
                it.second++;
            }
        }
        j++;
    }
    build();
    #ifdef debug
        cout<<"Time Taken :"<<float(clock()-start_time)/CLOCKS_PER_SEC<<'\n';
        printTree();
    #endif

    return 0;
}
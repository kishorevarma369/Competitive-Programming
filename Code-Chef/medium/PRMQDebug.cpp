#include<bits/stdc++.h>

using namespace std;

map<int,int> arr[262144];
map<int,int> numbers[1000001];
vector<int> primes;
bool processed[100005];

int n,N,l,r,ans=0,x,y;
//assume  i have primes then
int nearest_power2(int val)
{
    int c=0;
    while(val)
    {
        val>>=1;
        c++;
    }
    return 1<<c;
}

void build()
{
    int val,tval;
    int j=(n-2)/2;
    for(int i=0;i<N;i++)
    {
        // cin>>val;
        val=2+rand()%999999;
        tval=val;
        if(!processed[val])
        {
            int c=0;
            auto &primelist=numbers[val];
            for(auto &prime:primelist)
            {
                c=0;
                while((val%prime.first)==0)
                {
                    val/=prime.first;
                    c++;
                }
                prime.second=c;
            }
            processed[tval]=1;
        }
        arr[j]=numbers[tval];
        j++;
    }
    j--;
    int parent=(j-1)/2,child1,child2;
    int tmpsum=0;
    while(parent>=0)
    {
        child1=2*parent+1;
        child2=2*parent+2;
        auto &childlist1=arr[child1];
        auto &childlist2=arr[child2];
        auto &parentlist=arr[parent];
        tmpsum=0;
        for(auto &node:childlist1)
        {
            parentlist[node.first]+=node.second;
            tmpsum+=node.second;
            node.second=tmpsum;
        }
        tmpsum=0;
        for(auto &node:childlist2)
        {
            parentlist[node.first]+=node.second;
            tmpsum+=node.second;
            node.second=tmpsum;
        }
        parent--;
    }
    auto &childlist=arr[0];
    tmpsum=0;
    for(auto &node:childlist)
    {
        tmpsum+=node.second;
        node.second=tmpsum;
    }
    //print tree 
    // int k=j;
    // for(int i=0;i<=k;i++)
    // {
    //     auto &factlist=arr[i];
    //     printf("Node : %d\n",i);
    //     for(auto &node:factlist)
    //     {
    //         printf("( %d,%d )",node.first,node.second);
    //     }
    //     putchar('\n');
    // }
}

bool isprime(int val)
{
    bool prime=true;
    for(auto primeno:primes)
    {
        if(primeno*primeno>val){
            return true;
        }
        if((val%primeno)==0){
            return false;
        }
    }
    return true;
}

void pre()
{
    primes.reserve(78500);
    primes.push_back(2);
    for(int i=2;i<=1000000;i+=2) numbers[i][2]++;
    for(int i=3;i<1000000;i+=2)
    {
        if(isprime(i))
        {
            primes.push_back(i);
            for(int j=i;j<=1000000;j+=i) numbers[j][i]++;
        }
    }
}

void query(int node,int beg,int end)
{
    if(r<beg||l>end) return;
    if(l<=beg&&end<=r)
    {
        int tmp1=0,tmp2=0;
        if(x==y)
        {
            ans+=arr[node][x];
            return;
        }
        auto it2=arr[node].lower_bound(x);
        auto it1=arr[node].lower_bound(y);
        //handle some cases
        if(it2==arr[node].end()) return;
        if(it2!=arr[node].begin()){
            it2--;
            tmp2=it2->second;
        }
        if(it1==arr[node].end()){
            it1--;
            if(it1->first>=x)
            {
                tmp1=it1->second;
            }
        }else
        {
            if(it1->first>y)
            {
                if(it1!=arr[node].begin()){
                    it1--;
                    tmp1=it1->second;
                }
            }
            else tmp1=it1->second;
        }
        ans+=tmp1-tmp2;
        return;
    }
    query(1+node*2,beg,(beg+end)/2);
    query(2+node*2,(beg+end)/2+1,end);
}

int main()
{
    auto start=clock();
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    pre();
    int q;
    N=1+rand()%100000;
    n=nearest_power2(N);
    build();
    q=1+rand()%100000;
    while(q--)
    {
        // cin>>l>>r>>x>>y;
        l=rand()%N;
        r=rand()%N;
        x=1+rand()%1000000;
        y=x+rand()%(1000001-x);
        ans=0;
        query(0,0,N-1);
    }
    cout<<float(clock()-start)/CLOCKS_PER_SEC<<'\n';
    return 0;
}
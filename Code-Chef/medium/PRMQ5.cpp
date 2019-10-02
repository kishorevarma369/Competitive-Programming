#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> arr[266666];
int primes[1000001];

// #define debug
// #define testing_time

int n,N,l,r,ans=0,x,y;
//assume  i have primes then
int nearest_power2(int val)
{
    assert(val>0);
    if((val&(val-1))==0) return val;
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

void merge_routine(vector<pair<int,int>> &arr1,vector<pair<int,int>> &arr2,vector<pair<int,int>> &farr)
{
    auto it1=arr1.begin(),it2=arr2.begin();
    int a,b,aval=0,bval=0;
    while(it1!=arr1.end()&&it2!=arr2.end())
    {
        a=it1->first;
        b=it2->first;
        if(a==b)
        {
            farr.push_back({a,it1->second+it2->second});
            aval=(it1->second+=aval);
            bval=(it2->second+=bval);
            it1++;
            it2++;
        }
        else if(a>b)
        {
            farr.push_back(*it2);
            bval=(it2->second+=bval);
            it2++;
        }
        else{
            farr.push_back(*it1);
            aval=(it1->second+=aval);
            it1++;
        }
    }
    while(it1!=arr1.end())
    {
        farr.push_back(*it1);
        aval=(it1->second+=aval);
        it1++;
    }
    while(it2!=arr2.end())
    {
        farr.push_back(*it2);
        bval=(it2->second+=bval);
        it2++;
    }
}

void build()
{
    int parent=(n+N-1)/2;
    for(;parent>0;parent--)
    {
        merge_routine(arr[2*parent],arr[2*parent+1],arr[parent]);
    }
    auto &tlist=arr[1];
    int tsum=0;
    for(auto &pr:tlist)
    {
        tsum=(pr.second+=tsum);
    }
}

int rsearch(vector<pair<int,int>> &flist)
{
    auto it=lower_bound(flist.begin(),flist.end(),make_pair(x,0));
    if(it!=flist.begin())
    {
        it--;
        return it->second;
    }
    return 0;
}

int rsearch1(vector<pair<int,int>> &flist)
{
    auto it=upper_bound(flist.begin(),flist.end(),make_pair(y,INT_MAX));
    if(it!=flist.begin())
    {
        it--;
        return it->second;
    }
    return 0;
}


void nquery()
{
    int t1,t2;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            //perform
            t1=rsearch(arr[l]);
            t2=rsearch1(arr[l]);
            ans+=t2-t1;
            l++;
        }
        if(r&1)
        {
            --r;
            t1=rsearch(arr[r]);
            t2=rsearch1(arr[r]);
            ans+=t2-t1;
        }
    }
}


void query(int node,int beg,int end)
{
    if(r<beg||end<l) return;
    if(l<=beg&&end<=r)
    {
        //find solution
        auto &factorslist=arr[node];
        //find sum from x to y
        int tmp1=0,tmp2=0,csum=0;
        auto it1=lower_bound(factorslist.begin(),factorslist.end(),make_pair(x,0));
        auto it2=lower_bound(factorslist.begin(),factorslist.end(),make_pair(y,0));
        if(it1!=factorslist.begin())
        {
            it1--;
            tmp1=it1->second;
        }
        else tmp1=0;
        if(it2!=factorslist.end()&&it2->first==y)
        {
            tmp1=it2->second;
        }
        else if(it2!=factorslist.begin())
        {
            it2--;
            if(it2->first>=x){
                tmp2=it2->second;
            }
            else tmp2=0;
        }
        else tmp2=0;
        if(tmp2>=tmp1) ans+=tmp2-tmp1;
        else{
            cout<<x<<' '<<y<<' '<<tmp1<<' '<<tmp2<<'\n';
            system("pause");
        }
        return;
    }
    query(2*node,beg,(beg+end)/2);
    query(2*node+1,(beg+end)/2+1,end);
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    #ifdef debug
        auto start_time=clock();
    #endif
    
    primegen();
    int q,val,c,x1,y1;

    #ifdef testing_time
        N=1e5;
    #else
        cin>>N;
    #endif

    n=nearest_power2(N);
    assert(2*n<266666);
    int j=n,t1,t2;
    for(int i=0;i<N;i++)
    {
        #ifdef testing_time
            val=2+rand()%999999;
        #else
            cin>>val;
        #endif

        auto &primelist=arr[j];
        while(val>1){
            t1=primes[val];
            c=0;
            while((val%t1)==0)
            {
                val/=t1;
                c++;
            }
            primelist.push_back({t1,c});
        }
        j++;
    }
    build();    
    #ifdef testing_time
        // q=1+rand()%1000000;
        q=1000000;
    #else
        cin>>q;
    #endif

    while(q--)
    {
        #ifdef testing_time
            l=1+rand()%N;
            r=l+rand()%(N-l+1);
            x=1+rand()%1000000;
            y=x+rand()%(1000000-x+1);
        #else
            cin>>l>>r>>x>>y;
        #endif
        l--;
        r--;
        ans=0;
        nquery();
        #ifndef testing_time
            cout<<ans<<'\n';
        #endif
    }

    #ifdef debug
        cout<<"Time Taken :"<<float(clock()-start_time)/CLOCKS_PER_SEC<<'\n';
        // printTree();
    #endif

    return 0;
}
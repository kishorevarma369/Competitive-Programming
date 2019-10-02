#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,k;
	    cin>>n>>k;
	    vector<long long int> v[n+1];
	    long long int  profit=0;
	    long long int  value[n+1];
	    int visited[n+1]={0};
	    for(int i=1;i<=n;i++)
	    {
	        cin>>value[i];
	        profit+=value[i];
	    }
	    for(int i=1;i<n;i++)
	    {
	        long long int  x,y;
	        cin>>x>>y;
	        v[x].push_back(y);
	        v[y].push_back(x);
	    }
	    vector<long long int> lot[n+1];
        long long int finans[n+1];
	    lot[0].push_back(1);
        visited[1]=1;
	    int i;
	    for(i=1;i<n;i++)
	    {
	        if(lot[i-1].size()==0) break;
	        for(int j=0;j<lot[i-1].size();j++)
	        {
	            long long int  xx=lot[i-1][j];
	            for(int k=0;k<v[xx].size();k++)
	            {
	                if(!visited[v[xx][k]]){
                        visited[v[xx][k]]=xx;
                        lot[i].push_back(v[xx][k]);
                    }
                }
	        }
	    }
	    int pp=i;
	    
	    /*for(int i=0;i<pp;i++)
	    {
	        for(int j=0;j<lot[i].size();j++)
	        {
	            cout<<lot[i][j]<<" ";
	            
	        }
	        cout<<endl;
	    }*/
	    
	    int flag=1;
	    for(i=pp;i>=0;i--)
	    {
            for(int j=0;j<lot[i].size();j++)
            {
                long long int xx=lot[i][j];
                finans[xx]=value[xx];
                if(v[xx].size())
                for(auto &child:v[xx])
                {
                    if(child!=visited[xx]) finans[i]+=finans[child];
                }
                finans[i]=max(-k,finans[i]);
            }
	    }
        cout<<finans[1]<<'\n';
	}
	return 0;
}
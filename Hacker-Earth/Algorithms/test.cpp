/* Read input from STDIN. Print your output to STDOUT*/
#include<bits/stdc++.h>

using namespace std;

// int n;
// vector<int> v(10001);

// int findsol(int pos)
// {
// 	if(pos<n)
// 	{
// 		return max(findsol(pos+1))
// 	}
// 	return 0;
// }

// void solve()
// {
// 	cin>>n;
// 	for(int i=0;i<n;i++) cin>>v[i];
// 	cout<<findsol(0);
// }
void solve()
{
	int n;
	cin>>n;
	vector<int> v(n+1),oans(n+1);
	vector<pair<int,int>> ans(n+1);
	cin>>v[1];
	bool flag=0;
	int maxmin=INT_MIN;
	if(v[1]>=0)
	{
		flag=1;
		ans[1].first=v[1];
		ans[1].second=0;
		oans[1]=v[1];
	}
	for(int i=2;i<=n;i++)
	{
		cin>>v[i];
		if(v[i]<0)
		{
			ans[i]=ans[i-1];
			oans[i]=oans[i-1];
			maxmin=max(maxmin,v[i]);
			continue;
		}
		else flag=1;
		ans[i].first=oans[i-2]+v[i];
		ans[i].second=oans[i-1];
		oans[i]=max(ans[i].first,ans[i].second);
	}
	if(!flag)
	{
		cout<<maxmin<<'\n';
		return;
	}
	for(int i=n;i>0;i--)
	{
		if(v[i]>0)
		{
			if(oans[i]==ans[i].first)
			{ 
				// if(oans[i-1]==oans[i])
				// {
					
				// }
				if(ans[i].first==ans[i].second)
				{
					if(v[i]<v[i-1]) continue;
				}
				cout<<v[i],i--;
			}
		}
	}
	cout<<'\n';
}
int main(int argc, char *a[])
{
	//Write code here
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

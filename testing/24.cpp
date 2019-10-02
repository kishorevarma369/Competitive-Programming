
#include <bits/stdc++.h> 
using namespace std; 

void func() 
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i]; 
	queue<int> q; 
	sort(v.begin(), v.end()); 
	q.push(v[0]); 
	for (int i = 1; i < n; i++) { 
		int now = q.front(); 
		if (v[i] >  now) 
			q.pop(); 
		q.push(v[i]); 
	} 
	cout<<q.size()<<'\n';
} 

int main() 
{ 
	int t;
    cin>>t;
    while(t--) func();
	return 0; 
} 

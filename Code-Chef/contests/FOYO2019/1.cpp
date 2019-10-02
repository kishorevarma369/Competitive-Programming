#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;
set<ll> s={6,28,496,8128,33550336,8589869056,137438691328};
int main(){
	ll num;
	cin>>num;
	if(s.find(num)!=s.end()){
		printf("Perfect");
	}	
	else{
		printf("Not Perfect");
	}
	return 0;
}
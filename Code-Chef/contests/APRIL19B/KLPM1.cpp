#include <iostream>
using namespace std;
int ispali(string s)
{
    int low =0;
    int high=s.size()-1;
    while(low<=high)
    {
        if(s[low]!=s[high]) return 0;
        low++;
        high--;
    }
    return 1;
}
int findInnerSubstrings(string t,string s)
{
    int n=s.size();
    int count=0;
    for (int i = 0; i < n; i++)
	{
	    for (int j = 1; j <= n - i; j++) 
	    {
	        string check=t+s.substr(i,j);
	        if(ispali(check))  count++;
	    }
	}
	return count;
}
int main() {
	string s;
	cin>>s;
	int n=s.size();
	long long int count=0;
	for (int i = 0; i < n; i++)
	{
	    for (int j = 1; j <= n - i; j++) 
	    {
	        count+=findInnerSubstrings(s.substr(i,j),s.substr(i+j,n-j));
	    }
	}
    cout<<count<<endl;
	return 0;
}
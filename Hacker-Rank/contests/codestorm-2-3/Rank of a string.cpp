/*
https://www.hackerrank.com/contests/codestorm-2-3/challenges/rank-of-a-string/problem
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    string s,org;
    int i=1;
    cin>>s;
    org=s;
    sort(s.begin(),s.end());
    do
    {
        if(s==org) break;
        i++;
    }while(next_permutation(s.begin(),s.end()));
    cout<<i;
    return 0;
}

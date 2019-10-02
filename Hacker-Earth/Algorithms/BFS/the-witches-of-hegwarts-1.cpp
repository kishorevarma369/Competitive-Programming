/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/the-witches-of-hegwarts-1/
Question :The Witches of HEgwarts! 
Solution by :Kishore Varma
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int min_moves[1000001];

void pre()
{
    min_moves[2]=min_moves[3]=1;
    int x,y,z;
    for(int i=4;i<1000001;i++)
    {
        x=(((i%2)==0)?min_moves[i/2]:INT_MAX);
        y=(((i%3)==0)?min_moves[i/3]:INT_MAX);
        z=min_moves[i-1];
        min_moves[i]=min(x,y);
        min_moves[i]=min(min_moves[i],z)+1;
    }
}

int sol_help(int val)
{
    if(val<=1000000) return min_moves[val];
    int t_ans=val-2;
    bool calc=false;
    if(val%2==0) t_ans=min(t_ans,sol_help(val/2));
    else t_ans=min(t_ans,sol_help(val-1)),calc=1;
    if(val%3==0) t_ans=min(t_ans,sol_help(val/3));
    else if(!calc) t_ans=min(t_ans,sol_help(val-1));
    return t_ans+1;
}

void solve()
{
    int n;
    cin>>n;
    cout<<sol_help(n)<<'\n';
}

int main()
{
    pre();
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}


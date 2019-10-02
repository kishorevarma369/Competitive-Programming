#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<string> notpossible={"grid","snot","poss","ible"} ;
set<string> tofill;
vector<string> ans={"----","----","----","----"};

void solve(vector<string> grid)
{
    
}

int main()
{
    int n;
    cin>>n;
    string s,tmp;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        tmp=s;
        reverse(tmp.begin(),tmp.end());
        if(tofill.find(s)==tofill.end()&&tofill.find(tmp)==tofill.end())
        {
            tofill.insert(s);
        }
    }
    solve(ans);
    return 0;
}
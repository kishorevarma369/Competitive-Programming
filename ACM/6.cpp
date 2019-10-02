#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
vector<string> vs;
vector<string> final_ans;
bool ans_found=false;
int n;

void find_ans(int i,vector<string> board,vector<int> used)
{
    if(ans_found) return;
    if(i==4)
    {
        for(int node=0;node<used.size();node++)
        {
            if(!used[node]){
                int j,k;
                bool found_str=false;
                for(j=0;j<4;j++)
                {
                    for(k=0;k<4;k++)
                    {
                        if(vs[node][k]!=board[k][j]) break;
                    }
                    if(k==4){ 
                        found_str=true;
                        break;
                    }
                }
                if(!found_str) return;
            }
        }
        final_ans=board;
        ans_found=true;
        return;
    }
    auto tmp=board[i];
    for(int j=0;j<n;j++)
    {
        if(!used[j])
        {
            used[j]=1;
            board[i]=vs[j];
            find_ans(i+1,board,used);
            used[j]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    auto invalid="grid\nsnot\nposs\nible\n";
    while(t--)
    {
        cin>>n;
        set<string> mset;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            // if(mset.find(s)==mset.end())
            // {
            //     auto s1=s;
            //     reverse(s.begin(),s.end());
            //     if(mset.find(s)==mset.end()) {
            //         if(s<s1) mset.insert(s);
            //         else mset.insert(s1);
            //     }
            // }
            mset.insert(s);
            reverse(s.begin(),s.end());
            mset.insert(s);
        }
        n=mset.size();
        if(n>16)
        {
            cout<<invalid<<'\n';
            continue;
        }        
        ans_found=false;
        final_ans.clear();
        vector<string> ans(4,string(4,'A'));
        vs.clear();
        vs.reserve(n);
        for(auto &ts:mset) vs.push_back(ts);
        sort(vs.begin(),vs.end());
        if(n<=4){
            for(int i=0;i<n;i++)
            {
                ans[i]=vs[i];
            }
            for(int i=0;i<4;i++)
            {
                cout<<ans[i]<<'\n';
            }
            cout<<'\n';
            continue;
        }
        find_ans(0,ans,vector<int>(n,0));
        // cout<<"\n final ans size "<<final_ans.size()<<'\n';
        if(final_ans.size())
        {
            // cout<<'\n';
            for(auto &str:final_ans) cout<<str<<'\n';
            cout<<'\n';
        }
        else cout<<invalid<<'\n';
    }
    return 0;
}
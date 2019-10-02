#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;
auto invalid="grid\nsnot\nposs\nible\n";
vector<string> words,rwords;
vector<string> final_ans;//all solutions
int n;

void printans(vector<string> &board)
{
    cout<<"-----------------------------------\n";
    for(auto &row:board)
    {
        cout<<row<<'\n';
    }
    cout<<"-----------------------------------\n";
}
void findsol(int r,vector<string> board,vector<int> used,int filled=0)
{
    //handle completed board
    if(r==4||filled==n)
    {
        // printans(board);
        for(int i=0,k,j,l;i<n;i++)
        {
            if(!used[i])
            {
                for(j=0;j<4;j++)
                {
                    for(k=0;k<4;k++)
                    {
                        if(words[i][k]!=board[j][k]) break;
                    }
                    for(l=0;l<4;l++)
                    {
                        if(rwords[i][l]!=board[j][l]) break;
                    }
                    if(k==4||l==4) break;
                }
                if(j==4) return;
            }
        }
        for(auto &row:board)
        {
            for(auto &ch:row) if(ch=='.') ch='A';
        }
        // printans(board);
        if(final_ans.size()){
            if(!lexicographical_compare(final_ans.begin(),final_ans.end(),board.begin(),board.end())) final_ans=board;
        }else final_ans=board;
    }
    for(int i=0;i<n;i++){
        if(!used[i])
        {
            used[i]=1;
            board[r]=words[i];
            findsol(r+1,board,used,filled+1);
            board[r]=rwords[i];
            findsol(r+1,board,used,filled+1);
            used[i]=0;
        }
    }
}


void solve()
{
    cin>>n;
    string s,s1;
    set<string> myset;
    words.clear();
    rwords.clear();
    final_ans.clear();
    for(int i=0;i<n;i++){
        cin>>s;
        s1=s;
        reverse(s.begin(),s.end());
        if(s<s1) myset.insert(s);
        else myset.insert(s1);
        // myset.insert(s);
    }
    n=myset.size();
    if(n>8){
        cout<<invalid;
        return;
    }
    words.reserve(n);
    rwords.reserve(n);
    for(auto word:myset){
        words.push_back(word);
        cout<<word<<' ';
        reverse(word.begin(),word.end());
        rwords.push_back(word);
        cout<<word<<'\n';
    }
    findsol(0,vector<string>(4,string(4,'.')),vector<int>(n,0));
    
    printans(final_ans);
    // for(auto &row:final_ans)
    // {
    //     cout<<row<<'\n';
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<'\n';
    }
    return 0;
}
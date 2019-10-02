#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int calculate(string &s)
{
    int cou=0;
    for(int i=1;i<s.size();i++) if(s[i]!=s[i-1]) cou++;
    return cou;
}

typedef struct{
    int level,calcval;
}node;

void find_new_val(string &s,int i,int prevval,int &val)
{
    val=prevval;    
    if(i-1>=0&&s[i-1]!=s[i]) val--;
    if(i+1<s.size()&&s[i]!=s[i+1]) val--;
}

void process_new_val(string &s,int i,int &val)
{  
    s[i]=(s[i]-'a'+1)%26+'a';
    if(i-1>=0&&s[i-1]!=s[i]) val++;
    if(i+1<s.size()&&s[i]!=s[i+1]) val++;
}

int bfs(string s,int k)
{
    map<string,node> visited;
    int tmp=calculate(s);
    if(tmp<=k) return 0;
    visited[s]={0,tmp};
    queue<string> q;
    q.push(s);
    int mysize=s.size();
    node hema;
    int newcalval;
    char back;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        hema=visited[s];
        for(int i=0;i<mysize;i++)
        {
            find_new_val(s,i,hema.calcval,newcalval);
            back=s[i];
            process_new_val(s,i,newcalval);
            if(visited.find(s)==visited.end()){

                if(newcalval<=k){
                    cout<<s<<" "<<q.size()<<endl;
                    return hema.level+1;
                } 
                visited[s]={hema.level+1,newcalval};
                if(newcalval<=hema.calcval) q.push(s);
            }
            s[i]=back;
        }
    }
    return -1;
}

// string gen()
// {
    
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    string s;
    cin>>s;
    cin>>k;
    cout<<bfs(s,k)<<'\n';
    return 0;

}
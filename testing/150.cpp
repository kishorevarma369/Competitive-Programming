#include<bits/stdc++.h>

using namespace std;
int main() {
    queue<int> v[10];
    string s;
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;i<int(s.size());i++) v[s[i]-'0'].push(i);
    vector<int> to_remove;
    for(int i=0;i<10;i++) if((v[i].size()&1)==1) to_remove.push_back(i);
    if(to_remove.size())
    {
        int ans=INT_MAX,val,not_done=true;
        while(not_done)
        {
            int min_val=INT_MAX,min_pos=-1,max_val=INT_MIN,max_pos=-1;
            for(auto row:to_remove)
            {
                if(v[row].size()){
                    val=v[row].front();
                    if(min_val>val)
                    {
                        min_val=val;
                        min_pos=row;
                    }
                    if(max_val<val)
                    {
                        max_val=val;
                        max_pos=row;
                    }
                    // min_val=min(min_val,val);
                }
                else not_done=false;
                
            }
            if(not_done) {
                ans=min(ans,max_val-min_val);
                v[min_pos].pop();
            }
        }
        cout<<ans<<'\n';
    }
    else cout<<"-1\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,val;
    map<string,int> m;
    set<string> p;
    bool flag;
    cin>>n;
    string name;
    for(int i=0;i<n;i++)
    {
        cin>>name;
        flag=false;
        if(m.find(name)==m.end())
        {
            for(int i=1;i<=name.size();i++)
            {
                auto t=name.substr(0,i);
                if(p.find(t)==p.end())
                {
                    if(!flag)
                    {
                        cout<<t<<'\n';
                        m[name]++;
                    } 
                    p.insert(t);
                    flag=true;
                }
            }
            if(!flag)
            {
                cout<<name<<'\n';
                m[name]++;
            }
        }
        else
        {
            val=++m[name];
            cout<<(name+' '+to_string(val))<<'\n';
        }
    }
    return 0;   
}
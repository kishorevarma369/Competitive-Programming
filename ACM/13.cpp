#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
vector<pair<char,int>> v={{'L',0},{'W',-1},{'W',2},{'W',1},{'L',0},{'W',+1},{'L',0},{'W',-1}};

bool printstate(ll &val)
{
    ll tval;
    if(val==1){ cout<<"Win\n-1\n"; val--;return 1;}
    else
    {
        tval=(val-2)%8;
        if(v[tval].first=='W') 
        {
            cout<<"Win\n";
            if(v[tval].second==-1) cout<<"-1\n",val--;
            else if(v[tval].second==1) cout<<"+1\n",val++;
            else val/=2,cout<<"/2\n";
        }
        else {cout<<"Lose\n";return false;}
    }
    return true;
}

void print(ll &val)
{
    ll tval;
    if(val==1) cout<<"-1\n";
    else{
        tval=(val-2)%8;
        if(v[tval].second==1) cout<<"+1\n",val++;
        else if(v[tval].second==2) cout<<"/2\n",val/=2;
        else cout<<"-1\n",val--;
    }
}

int main()
{
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        ll n,tmp,c=0;
        cin>>n;
        if(printstate(n))
        {
            while(1){
                cin>>s;
                if(s=="GG") break;
                else if(s=="/2") n/=2;
                else if(s=="+1") n+=1;
                else n-=1;
                print(n);
            }
        }
        else cin>>s;
    }
    return 0;
}
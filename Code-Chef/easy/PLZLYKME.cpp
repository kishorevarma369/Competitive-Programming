#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int main(int argc, char const *argv[])
{
    ll t,d,s,c,l;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>l>>d>>s>>c;
        c++;
        if(d==1)
        {
            if(s>=l) cout<<"ALIVE AND KICKING\n";
            else cout<<"DEAD AND ROTTING\n";
            continue;
        }
        auto val=pow(float(l)/s,float(1)/(d-1));
        if(c>=val) cout<<"ALIVE AND KICKING\n";
        else cout<<"DEAD AND ROTTING\n";
    }
    return 0;
}

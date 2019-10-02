#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007ll

typedef long long int ll;

bool check(char a, char b,char c)
{
    vector<char> v(3);
    v[0]=a;
    v[1]=b;
    v[2]=c;
    sort(v.begin(),v.end());
    if(v[0]=='b'&&v[1]=='b'&&v[2]=='o') return true;
    return false;
}

int main(int argc, char const *argv[])
{
    ll t,i,j,k;
    cin>>t;
    string p,q;
    while(t--)
    {
        cin>>p>>q;
        if(check(p[0],p[1],p[2])) goto a;
        else if(check(p[0],p[1],q[2])) goto a;
        else if(check(p[0],q[1],p[2])) goto a;
        else if(check(p[0],q[1],q[2])) goto a;
        else if(check(q[0],p[1],p[2])) goto a;
        else if(check(q[0],p[1],q[2])) goto a;
        else if(check(q[0],q[1],p[2])) goto a;
        else if(check(q[0],q[1],q[2])) goto a;
        b:
        cout<<"no\n";
        continue;
        a:
        cout<<"yes\n";
    }
    return 0;
}

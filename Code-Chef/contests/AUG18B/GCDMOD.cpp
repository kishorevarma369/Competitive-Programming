#include<bits/stdc++.h>

using namespace std;

#define mymod 1000000007ll
#define powermod modpow
typedef long long int ll;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main(int argc, char const *argv[])
{
    ll a,b,t,p,q,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        p=b;
        q=a-b;
        if(q==0)
        {
            cout<<(2ll*powermod(p,n,mymod))%mymod<<'\n';
            continue;
        }
        p=powermod(p,n,q);
        p=((2ll%q)*p)%q;
        if(p==0) cout<<q%mymod;
        else cout<<__gcd(q,p)%mymod;
        cout<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define mynum 1000007
bool prime[mynum];

void pre()
{
    for(int i=3;i<mynum;i+=2) prime[i]=true;
    prime[2]=true;
    for(int i=3;i<mynum;i+=2)
    {
        if(prime[i])
        {
            for(int j=i+i;j<mynum;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

void find_prime_substrings(string s,set<int> &fprimes)
{
    int si=int(s.size()),val;
    for(int i=0;i<si;i++)
    {
        val=0;
        for(int j=i;j<si;j++)
        {
            val=val*10+s[j]-'0';
            if(prime[val]) fprimes.insert(val);
        }    
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    pre();
    cin>>t;
    while(t--)
    {
        set<int> fprimes;
        string s;
        cin>>s;
        list<int> q;
        auto p=s.substr(0,6);
        int val=0;
        for(int i=0;i<p.size();i++)
        {
            val=0;
            for(int j=i;j<p.size();j++)
            {
                val=val*10+p[j]-'0';
                if(prime[val]) fprimes.insert(val);
            } 
            q.push_back(val);
        }
        for(int i=6;i<s.size();i++)
        {
            q.pop_front();
            val=s[i]-'0';
            for(auto &l:q)
            {
                l=l*10+val;
                if(prime[l]) fprimes.insert(l);
            }
            q.push_back(val);
            if(prime[val]) fprimes.insert(val);
        }
        cout<<fprimes.size()<<'\n';
    }
    return 0;
}

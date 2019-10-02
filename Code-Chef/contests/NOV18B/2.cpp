#include<bits/stdc++.h>

using namespace std;

int mymax=0,pb=0,pe=0,k,shift=0;

void perform_rshift(list<int> &a)
{
    if(a.back()<0)
    {
        a.back()++;
        if(a.front()<0) a.front()--;
        else a.push_front(-1);
    }
    else
    {
        a.back()--;
        if(a.front()>0) a.front()++;
        else a.push_front(1);
    }
    if(a.back()==0) a.pop_back();
    mymax=max(mymax,a.front());
}

void calc_mymax(list<int> &a)
{
    mymax=0;
    int pos=0;
    for(auto &i:a)
    {
        if(i>mymax)
        {
            mymax=i;
            pb=pos;
        } 
        if(i>0) pos+=i;
        else pos+=-i;
    } 
    mymax=min(k,mymax);
    pe=pb+mymax;
}

int main()
{
    int n,q,val;
    cin>>n>>q>>k;
    list<int> a;
    cin>>val;
    if(val) a.push_back(1);
    else a.push_back(-1);
    for(int i=1;i<n;i++)
    {
        cin>>val;
        if(val)
        {
            if(a.back()>0) ++a.back();
            else a.push_back(1);
        }
        else
        {
            if(a.back()<0) --a.back();
            else a.push_back(-1);
        }
    }
    char ch;
    int flag=0;
    calc_mymax(a);
    string s;
    cin>>s;
    if(int(a.size())==1)
    {
        mymax=min(k,mymax);
        for(auto &ch:s) if(ch=='?') cout<<mymax<<'\n';
        return 0;
    }
    for(auto &ch:s)
    {
        if(ch=='!') perform_rshift(a),flag=1,shift++;
        else
        {
            shift%=n;
            if(flag)
            {
                if(pe>n-1-shift) calc_mymax(a);
            }
            flag=0;
            cout<<min(k,mymax)<<'\n';
        }
    }
    return 0;
}
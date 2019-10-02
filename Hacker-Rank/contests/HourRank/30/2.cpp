#include <bits/stdc++.h>

using namespace std;

string prefix,infix;

void prefix_to_infix()
{
    stack<string> s;
    string t;
    for(int i=prefix.size()-1;i>=0;i--)
    {
        if(prefix[i]=='?') s.push("?");
        else
        {
            auto a=s.top();s.pop();
            auto b=s.top();s.pop();
            if(prefix[i]=='+') t="(" + a + "+" + b + ")";
            else t="(" + a + "-" + b + ")";
            s.push(t);
        }
    }
    infix=s.top();
}

int main()
{
    cin>>prefix;
    prefix_to_infix();
    cout<<infix<<'\n';
    prefix.clear();
    stack<char> s;
    s.push('+');
    vector<bool> v;
    int pos=0,neg=0;
    for(auto &ch:infix)
    {
        if(ch=='('){
            if(s.top()=='+') s.push('+');
            else s.push('-');
        } 
        else if(ch==')') s.pop();
        else if(ch=='?')
        {
            //got ?
            if(s.top()=='+') v.push_back(true),pos++;
            else v.push_back(false),neg++;
            s.pop();
        }
        else
        {
            //got symbol
            auto c=s.top();
            if(c=='-'&&ch=='-') s.push('+');
            else if(c=='-'||ch=='-') s.push('-');
            else s.push('+');
        }
    }
    int extra=abs(pos-neg);
    assert(pos>0);
    assert(neg>0);
    //+-?+??-+???
    if(pos<neg)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i])
            {
                cout<<(1+extra)<<'\n';
                extra=0;
            } 
            else cout<<"1\n";
        }
    }
    else if(pos>neg)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i]) cout<<"1\n";
            else 
            {
                cout<<(1+extra)<<'\n';
                extra=0;
            }
        }
    }
    else
    {
        for(int i=0;i<v.size();i++) cout<<"1\n";
    }
}
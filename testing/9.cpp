#include<bits/stdc++.h>

using namespace std;

class stk
{
    int a[100001],b[100001];
    int top;
    public:
    stk()
    {
        top=0;
    }
    void push(int val)
    {
        if(top==0)
        {
            a[top]=b[top]=val;
            top++;
            return;
        }
        if(b[top-1]>val)
        {
            b[top]=b[top-1];
        }
        else b[top]=val;
        a[top++]=val;
    }
    void pop()
    {
        if(top==0) return;
        top--;
    }
    int getMaxElement()
    {
        return b[top-1];
    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t,cmd,val;
    cin>>t;
    stk a=stk();
    while(t--)
    {
        cin>>cmd;
        switch(cmd)
        {
            case 1: cin>>val;
                    a.push(val);
                    break;
            case 2: a.pop();
                    break;
            case 3: cout<<a.getMaxElement()<<'\n';
        }
    }
    
    // transform();
    // process();
    
    return 0;
}
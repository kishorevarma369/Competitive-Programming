#include<bits/stdc++.h>

using namespace std;

class stk{
    vector<int> a;
    int top,max1pos;
    void calculate()
    {
        if(top>=2)
        {
            if(a[0]>=a[1]) max1pos=0,max2pos=1;
            else max1pos=1,max2pos=0;
            for(int i=2;i<top;i++)
            {
                if(a[i]>a[max1pos])
                {
                    max2pos=max1pos;
                    max1pos=i;
                }
                else if(a[i]>a[max2pos])
                {
                    max2pos=i;
                }
            }
        }
        else if(top==1)
        {
            max1pos=0;
            max2pos=-1;
        }
        else max1pos=-1,max2pos=-1;
    }
    public:
    stk(int n=100001)
    {
        a.resize(n);
        top=0;
        max1pos=-1;
    }
    void push(int val)
    {
        if(top==0)
        {
            max1pos=top;
            a[top++]=val;
            return;
        }
        if(max1pos==-1) calculate();
        if(val>a[max1pos]) max1pos=top;
        a[top++]=val;
    }
    void pop()
    {
        if(!top) return;
        if(max1pos==-1) calculate();
        top--;
        if(top==max1pos)
        {
            max1pos=max2pos;
            max2pos=-1;
        }
        else if(top==max2pos)
        {
            max2pos=-1;
        }
        top--;
    }
    int getMaxElement()
    {
        if(max1pos==-1) calculate();
        if(max1pos!=-1) return a[max1pos];
        return INT_MIN;
    }
};

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t,cmd,val;
    cin>>t;
    stk a=stk(t+5);
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
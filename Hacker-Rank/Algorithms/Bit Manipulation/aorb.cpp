#include<bits/stdc++.h>

using namespace std;

string A,B,C;
int cou;
map<char,int> hextoint;
map<int,char> inttohex;

void precompute()
{
    for(char i='0';i<='9';i++) hextoint[i]=int(i-'0'),inttohex[int(i-'0')]=i;
    for(char i='A';i<='F';i++) hextoint[i]=10+int(i-'A'),inttohex[10+int(i-'A')]=i;
}

void normalize()
{
    unsigned int mymax=0;
    mymax=max(mymax,A.size());
    mymax=max(mymax,B.size());
    mymax=max(mymax,C.size());
    for(int i=A.size();i<mymax;i++) A='0'+A;
    for(int i=B.size();i<mymax;i++) B='0'+B;
    for(int i=C.size();i<mymax;i++) C='0'+C;
}

void print()
{
    bool myflag=false;
    int i=0,mysize=A.size();
    while(i<mysize&&A[i]=='0') i++;
    if(i==mysize) cout<<"0";
    else for(;i<mysize;i++) cout<<A[i];
    cout<<'\n';
    i=0;
    while(i<mysize&&B[i]=='0') i++;
    if(i==mysize) cout<<"0";
    else for(;i<mysize;i++) cout<<B[i];
    cout<<'\n';
}

void unsetbit(int &val,int pos)
{
    int k=val&pos;
    if(k) val=(~k)&val;
}

void setbit(int &val,int pos)
{
    int k=val&pos;
    if(!k)
    {
        val|=pos;
    }
}

int myreverse(int val)
{
    int ans=0,k=1;
    while(val!=0||k<16)
    {
        ans<<=1;
        ans+=val&1;
        val>>=1;
        k<<=1;
    }
    return ans;
}

void compute(char &a0,char &b0,const char &c0)
{
    int a=myreverse(hextoint[a0]),b=myreverse(hextoint[b0]),c=myreverse(hextoint[c0]),k=1;
    int a1=a,b1=b;
    while(a!=0||b!=0||c!=0)
    {
        if(c&1)
        {
            if((a&1)|(b&1))
            {
                //haha don't need anything
            }
            else
            {
                setbit(b1,k);
                cou++;
            } 
        }
        else{
            cou+=(a&1)+(b&1);
            unsetbit(a1,k);
            unsetbit(b1,k);
        }
        k<<=1;
        a>>=1;
        b>>=1;
        c>>=1;
    }
    a0=inttohex[myreverse(a1)];
    b0=inttohex[myreverse(b1)];
}

void minimizeA_case1(char &a0,char &b0,const char &c0)
{
    int a=myreverse(hextoint[a0]),b=myreverse(hextoint[b0]),c=myreverse(hextoint[c0]),k=1;
    int a1=a,b1=b;
    while((a!=0||b!=0||c!=0)&&cou>0)
    {
        if(c&1)
        {
            if(a&1)
            {
                if(b&1)
                {
                    unsetbit(a1,k);
                    cou--;
                }
                else if(cou>1)
                {
                    setbit(b1,k);
                    unsetbit(a1,k);
                    cou-=2;
                }
            }
            //else no need because of compute, if c has bit set then either a or b or bot has bit set
        }
        k<<=1;
        a>>=1;
        b>>=1;
        c>>=1;
    }
    a0=inttohex[myreverse(a1)];
    b0=inttohex[myreverse(b1)];
}
/*
void minimizeA_case2(char &a0,char &b0,const char &c0)
{
    int a=myreverse(hextoint[a0]),b=myreverse(hextoint[b0]),c=myreverse(hextoint[c0]),k=1;
    int a1=a,b1=b;
    while((a!=0||b!=0)&&cou>1)
    {
        if(c&1)
        {
            if(a&1)
            {
                unsetbit(a1,k);
                setbit(b1,k);
                cou-=2;
            }
        }
        k<<=1;
        a>>=1;
        b>>=1;
        c>>=1;
    }
    a0=inttohex[myreverse(a1)];
    b0=inttohex[myreverse(b1)];
}
*/

int main(int argc, char const *argv[])
{
    int t,k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    precompute();
    while(t--)
    {
        cin>>k;
        cin>>A>>B>>C;
        normalize();
        //cout<<A<<B<<C;
        cou=0;
        int mysize=int(A.size());
        for(int i=0;i<mysize;i++)  compute(A[i],B[i],C[i]);
        if(cou>k) cout<<"-1\n";
        else
        {
            cou=k-cou;
            for(int i=0;i<mysize&&cou>0;i++) minimizeA_case1(A[i],B[i],C[i]); 
            //for(int i=0;i<mysize&&cou>1;i++) minimizeA_case2(A[i],B[i],C[i]); 
            //cout<<"\n\n\n";
            //cout<<A<<'\n'<<B<<'\n';
            print();
        }
    }
    return 0;
}

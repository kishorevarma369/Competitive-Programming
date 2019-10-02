#include<bits/stdc++.h>
using namespace std;

string sub(string &a,string &b)
{
    int l=a.size(),borrow=0,c,d;
    string res(l,'0');
    for(int i=l-1;i>=0;i--){
        c=(a[i]-'0')-borrow;
        d=b[i]-'0';
        borrow=0;
        if(c-d>=0)
            res[i]=c-d+'0';
        else{
            borrow=1;
            res[i]=2+(c-d)+'0';
        }
    }
    return res;
}

string add(string &a,string &b)
{
    int l=a.size(),carry=0,c,d;
    string res(l,'0');
    for(int i=l-1;i>=0;i--){
        c=(a[i]-'0')+carry;
        d=b[i]-'0';
        carry=0;
        if(c+d>1)
        {
            res[i]=(c+d)%2+'0';
            carry=(c+d)/2;
        }
        else{
            res[i]=c+d+'0';
        }
    }
    if(carry)
    {
        res='1'+res;        
    }
    return res;
}

string bin(int val)
{
    string s;
    while(val)
    {
        s.push_back(val%2+'0');
        val/=2;
    } 
    reverse(s.begin(),s.end());
    // cout<<"reverse:"<<s<<endl;
    return s;
}

int main()
{
    int t,n,x=0,y=0;
    string a,b,result,z;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b;
        a+='0';b+='0';
        x=0,y=0;
        for(int i=0;i<n;i++) if(a[i]=='1') x++;
        for(int i=0;i<n;i++) if(b[i]=='1') y++;
        result=sub(b,a);
        if(y-x>0){
            z=bin(y-x);
            z=string(a.size()-z.size(),'0')+z;
            result=sub(result,z);
        }
        else
        {
            z=bin(x-y);
            z=string(a.size()-z.size(),'0')+z;
            result=add(result,z);
        }
        auto pp=result.find('1'); 
        if(pp!=string::npos)  cout<<result.substr(pp);

    }
    return 0;
}
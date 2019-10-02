#include<bits/stdc++.h>

using namespace std;

#define uplim 100005
#define mod 1000000007
#define multiply(val1,val2) (((val1%mod)*(val2%mod))%mod)
#define add(val1,val2) ((val1%mod+val2%mod)%mod)
#define substract(val1,val2) (((val1%mod)-(val2%mod)+mod)%mod)

typedef long long int ll;

ll ten_power[uplim],loss[uplim];

string a,b;

void pre()
{
    ten_power[0]=1;
    for(ll i=1;i<uplim;i++) ten_power[i]=10*ten_power[i-1];
    for(int i=2;i<uplim;i++) 
    {
        loss[i]=add(multiply(multiply(45ll,ten_power[i-2]),ten_power[i-2]),multiply(10ll,loss[i-1]));
    }
}

void decrement(string &a)
{
    int i=a.size(),carry=1,x;
    if(i==1&&a[0]=='0') return;
    i--;
    for(;i>=0;i--)
    {
        x=a[i]-'0'-carry;
        if(x>=0)
        {
            a[i]=x+'0';
            break;
        }
        else
        {
            carry=1;
            a[i]='9';
        }
    }
    if(a[0]=='0') a=a.substr(1);
}

ll find_orig_ans()
{
    // b*(b+1)/2-(a)*(a+1)/2 => orig_ans  
    ll orig_ans=0;
    ll alen=a.size(),blen=b.size();
    ll a_ans=0,b_ans=0;
    for(ll i=alen-1;i>=0;i--)
    {
        a_ans=add(a_ans,multiply(a[i]-'0',ten_power[alen-i-1]));
    }
    for(ll i=blen-1;i>=0;i--)
    {
        b_ans=add(b_ans,multiply(b[i]-'0',ten_power[blen-i-1]));
    }
    b_ans=multiply(b_ans,add(b_ans,1ll));
    a_ans=multiply(a_ans,add(a_ans,1ll));
    orig_ans=substract(b_ans,a_ans);
    orig_ans=multiply(orig_ans,500000004ll);
    return orig_ans;
}

ll find_loss(string &s)
{
    s='0'+s;
    ll my_loss=0,prev_loss=0,len=s.size();
    char ch;
    for(int i=1;i<len;i++)
    {
        ch='0';
        for(;ch<=s[i];ch++)
        {
            if(ch==s[i])
            {
                //some
                my_loss=add(my_loss,multiply(prev_loss,multiply(ch-'0',ten_power[len-i-1])));
                if(ch==s[i-1])
                {
                    my_loss=add(my_loss,multiply(ch-'0',ten_power[len-i-1]));
                    prev_loss=add(prev_loss,multiply(ch-'0',ten_power[len-i-1]));
                }
                break;
            }
            // (ch-'0')*ten_power[len-i-2]*ten_power[len-i-2]+loss[len-i-1];
            if(len-i>=2){ 
                my_loss=add(my_loss,multiply(ch-'0',multiply(ten_power[len-i-2],ten_power[len-i-2])));
                my_loss=add(my_loss,loss[len-i-1]);
            }
            if(ch==s[i-1])
            {
                my_loss=add(my_loss,multiply(ch-'0',multiply(ten_power[len-i-1],ten_power[len-i-1])));
            }
        }
    }
    return my_loss;
}

void process()
{
    int x,y;
    cin>>x>>a>>y>>b;
    decrement(a);
    ll orig_ans=find_orig_ans();
    ll loss_b=find_loss(b);
    ll loss_a=find_loss(a);
    orig_ans=substract(orig_ans,substract(loss_b,loss_a));
    // cout<<substract(loss_b,loss_a)<<'\n';
    cout<<orig_ans<<'\n';
}

int main()
{
    pre();
    int t;
    cin>>t;
    while(t--) process();
}
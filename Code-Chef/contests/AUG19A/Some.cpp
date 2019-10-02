#include<bits/stdc++.h>

using namespace std;

#define uplim 100001

#define mod 1000000007
typedef long long int ll;

ll ten_power[uplim];
ll loss[uplim];
ll ans=0,orig_ans;
string a,b;

#define multiply(val1,val2) (((val1%mod)*(val2%mod))%mod)
#define add(val1,val2) ((val1%mod+val2%mod)%mod)
#define substract(val1,val2) (((val1%mod)-(val2%mod)+mod)%mod)


void propagate(int i)
{
    while(i>=0)
    {
        if(a[i]=='9')
        {
            a[i]='0';
            i--;
        }
        else{
            a[i]++;
            break;
        }
    }
}

void print()
{
    cout<<"a="<<a<<'\n';
    cout<<"b="<<b<<'\n';
}


void pre()
{
    ten_power[0]=1;
    for(int i=1;i<uplim;i++) ten_power[i]=(ten_power[i-1]*10ll)%mod;
    for(int i=2;i<uplim;i++) 
    {
        loss[i]=add(multiply(multiply(45ll,ten_power[i-2]),ten_power[i-2]),multiply(10ll,loss[i-1]));
    }
    // loss[i]=((((45ll*ten_power[i-2])%mod)*ten_power[i-2])%mod+(9*loss[i-1])%mod)%mod;
}

void format_string()
{
    ll to_add=b.size()-a.size();
    if(to_add)
    {
        string to_add_str = string(to_add,'0');
        a=to_add_str+a;
    }
    ll len=a.size(),to_remove=0;
    for(ll i=0;i<len;i++)
    {
        if(a[i]!=b[i]) break;
        to_remove++;
    }
    if(to_remove==len)
    {
        for(ll i=len-1;i>0;i--)
        {
            if(b[i]==b[i-1])
            {
                ans=add(ans,multiply((b[i]-'0'),ten_power[len-i-1]));
            }       
        }
        return;
    }
    ll k=len-1;
    ll tans=1;
    for(;k>0;k--)
    {
        if(a[k]==a[k-1]){
            // ans=add(ans,multiply(multiply(tans,ten_power[len-1-k]),(a[k]-'0')));
            ans=add(ans,multiply(multiply((a[k]-'0'),ten_power[len-k-1]),tans));
        }
        tans=add(tans,multiply(('9'-a[k]),ten_power[len-1-k]));
    }
    a=a.substr(to_remove);
    b=b.substr(to_remove);
    len=a.size();
    if(len>1)
    {
        if(a[len-1]<a[len-2])
        { 
            ans+=a[len-1]-'0';
        }
        a[len-1]='0'; 
        propagate(len-2);
    }
    //find contribution of removed ones => no of times its repeated
}



void process()
{
    ll len=a.size();
    // len >= 2
    ll i=len-2;
    while(i>0)
    {
        // if(a[i-1]==a[i])
        for(;a[i]<='9';a[i]++)
        {
            ans=add(ans,add(multiply(multiply((a[i]-'0'),ten_power[len-i-2]),ten_power[len-i-2]),loss[len-i-1]));
            // ans+=(a[i]-'0')*ten_power[len-i-2]*ten_power[len-i-2]+loss[len-i-1];
            if(a[i]==a[i-1])
            {
                ans=add(ans,multiply(multiply((a[i]-'0'),ten_power[len-i-1]),ten_power[len-i-1]));
            }
        }
        a[i]='0';
        propagate(i-1);
        i--;
    }
    ll tlen=len-1;
    while(i>=0&&a[i]<b[i])
    {
        ans=add(ans,add(multiply(multiply((a[i]-'0'),ten_power[len-i-2]),ten_power[len-i-2]),loss[len-i-1]));
        a[i]++;
    }
    i++;
    for(;i<tlen;i++)
    {
        for(;a[i]<b[i];a[i]++)
        {
            ans=add(ans,add(multiply(multiply((a[i]-'0'),ten_power[len-i-2]),ten_power[len-i-2]),loss[len-i-1]));
            if(a[i-1]==a[i])
            {
                ans=add(ans,multiply(multiply((a[i]-'0'),ten_power[len-i-1]),ten_power[len-i-1]));
            }
        }
    }
    if(len>1)
    {
        for(;a[tlen]<b[tlen];a[tlen]++)
        {
            if(a[tlen]==a[tlen-1]) ans=add(ans,a[tlen]-'0');
        }
    }
    // if(len>1) a[tlen]=a[tlen-1];
    ll tans=1,lans=0;

    // print();

    for(;tlen>0;tlen--)
    {
        // cout<<ans<<'\n';
        if(a[tlen]==a[tlen-1])
        {
            ans=add(ans,multiply(multiply((a[tlen]-'0'),ten_power[len-tlen-1]),tans));
            // ans=add(ans,multiply(tans,multiply(a[tlen]-'0',ten_power[len-tlen-1])));
        }
        tans=add(tans,multiply((a[tlen]-'0'),ten_power[len-tlen-1]));
    }
}

void find_orig_ans()
{
    // b*(b+1)/2-(a-1)*(a)/2 => orig_ans  
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
    orig_ans=multiply(b_ans,add(b_ans,1ll));
    a_ans=multiply(a_ans,substract(a_ans,1));
    orig_ans=substract(orig_ans,a_ans);
    orig_ans=multiply(orig_ans,500000004ll);
}

int main()
{
    pre();
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cin>>b;
        // cin>>x>>a;
        // cin>>y>>b;
        ans=0,orig_ans=0;
        find_orig_ans();
        if(a!=b)
        {
            format_string();
            process();
        }
        else format_string();
        cout<<ans<<' ';
        ans=substract(orig_ans,ans);
        cout<<ans<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define uplim 100004

#define mod 1000000007
typedef long long int ll;

ll ten_power[uplim];
ll loss[uplim];
bool contributed[uplim];
ll loss_ans,orig_ans,common,len,t_loss_ans;
string a,b;

#define multiply(val1,val2) (((val1%mod)*(val2%mod))%mod)
#define add(val1,val2) ((val1%mod+val2%mod)%mod)
#define substract(val1,val2) (((val1%mod)-(val2%mod)+mod)%mod)


int propagate(int i)
{
    while(i>=common)
    {
        if(contributed[i])
        {
            contributed[i]=false;
            t_loss_ans=substract(t_loss_ans,multiply((a[i]-'0'),ten_power[len-i-1]));
            if(a[i]=='9')
            {
                a[i]='0';
                i--;
            }
            else{
                a[i]++;
                if(i>0&&a[i]==a[i-1]&&a[i]!='0')
                {
                    t_loss_ans=add(t_loss_ans,multiply((a[i]-'0'),ten_power[len-i-1]));
                    contributed[i]=true;
                }
                break;
            }
        }
        else
        {
            if(a[i]=='9')
            {
                a[i]='0';
                i--;
            }
            else{
                a[i]++;
                if(i>0&&a[i]==a[i-1]&&a[i]!='0')
                {
                    t_loss_ans=add(t_loss_ans,multiply((a[i]-'0'),ten_power[len-i-1]));
                    contributed[i]=true;
                }
                break;
            }
        }
    }
    return i;
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
}

void find_orig_ans()
{
    // b*(b+1)/2-(a-1)*(a)/2 => orig_ans  
    orig_ans=0;
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

void make_equal()
{
    int to_add_len=b.size()-a.size();
    if(to_add_len) a=string(to_add_len,'0')+a;
    len=b.size();
}

void find_common()
{
    common=0;
    for(ll i=0;i<len;i++)
    {
        if(a[i]!=b[i]) break;
        common++;
    }
}

void process()
{
    t_loss_ans=0,loss_ans=0;
    for(int i=0;i<uplim;i++) contributed[i]=0;
    make_equal();
    find_common();
    ll i=len-1;
    for(;i>0;i--)
    {
        if(a[i]==a[i-1])
        {
            t_loss_ans=add(t_loss_ans,multiply((a[i]-'0'),ten_power[len-i-1]));
            contributed[i]=true;
        }
    }
    loss_ans=t_loss_ans;
    if(common==len) return;
    // char prev_char=a[len-1];
    for(i=len-1,i=propagate(i);i>common;)
    {
        // if(prev_char=='9')
        // {
        //     // loss_ans=add(loss_ans,t_loss_ans);
        //     // // loss_ans=add(loss_ans,loss[len-i-1]);
        //     // // if(len-i>1) loss_ans=add(loss_ans,multiply(a[i]-'0',multiply(ten_power[len-i-2],ten_power[len-i-2])));
        //     prev_char=0;
        //     // i--;
        //     // if(i>common) pro
        //     continue;
        // }
        for(;a[i]<='9';)
        {
            loss_ans=add(loss_ans,t_loss_ans);
            loss_ans=add(loss_ans,loss[len-i-1]);
            if(len-i>1) loss_ans=add(loss_ans,multiply(a[i]-'0',multiply(ten_power[len-i-2],ten_power[len-i-2])));
            if(a[i]=='9')
            {
                i=propagate(i);
                break;
            }
            else propagate(i);
        }
    }
    i=common;
    while(a[i]<=b[i])
    {
        loss_ans=add(loss_ans,t_loss_ans);
        if(a[i]==b[i])
        {
            if(i>0&&a[i]==a[i-1])
            {
                t_loss_ans=add(t_loss_ans,multiply(a[i]-'0',multiply(ten_power[len-i-2],ten_power[len-i-2])));
            }
            break;
        }
        else{
            if(i>0&&a[i]==a[i-1])
            {
                loss_ans=add(loss_ans,multiply(a[i]-'0',multiply(ten_power[len-i-1],ten_power[len-i-1])));
            }
            loss_ans=add(loss_ans,loss[len-i-1]);
            if(len-i>1) loss_ans=add(loss_ans,multiply(a[i]-'0',multiply(ten_power[len-i-2],ten_power[len-i-2])));
            a[i]++;
        }
    }
    for(i++;i<len;i++)
    {
        for(;a[i]<=b[i];a[i]++)
        {
            loss_ans=add(loss_ans,t_loss_ans);
            if(a[i]==b[i]){
                if(a[i]==a[i-1]){
                    t_loss_ans=add(t_loss_ans,multiply(a[i]-'0',ten_power[len-i-1]));
                    // loss_ans=add(loss_ans,multiply(a[i]-'0',ten_power[len-i-1]));
                }
                break;
            }
            else{
                if(a[i]==a[i-1]) loss_ans=add(loss_ans,multiply(a[i]-'0',multiply(ten_power[len-i-1],ten_power[len-i-1])));
                loss_ans=add(loss_ans,loss[len-i-1]);
                if(len-i>1) loss_ans=add(loss_ans,multiply(a[i]-'0',multiply(ten_power[len-i-2],ten_power[len-i-2])));
            }
        }
    }
    if(len>1&&a[len-1]==a[len-2])
    {
        loss_ans=add(loss_ans,multiply(a[i]-'0',ten_power[len-i-1]));
    }
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
        find_orig_ans();
        process();
        cout<<loss_ans<<' ';
        loss_ans=substract(orig_ans,loss_ans);
        cout<<loss_ans<<'\n';
    }
    return 0;
}
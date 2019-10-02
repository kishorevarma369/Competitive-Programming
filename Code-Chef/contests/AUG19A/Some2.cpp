#include<bits/stdc++.h>

using namespace std;

#define uplim 100001

#define mod 1000000007
typedef long long int ll;

ll ten_power[uplim];
ll loss[uplim];
ll ans=0,orig_ans,common,len;
string a,b;

#define multiply(val1,val2) (((val1%mod)*(val2%mod))%mod)
#define add(val1,val2) ((val1%mod+val2%mod)%mod)
#define substract(val1,val2) (((val1%mod)-(val2%mod)+mod)%mod)


void propagate(int i)
{
    while(i>=common)
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

void make_equal()
{
    int to_add_len=b.size()-a.size();
    if(to_add_len) a=string(to_add_len,'0')+a;
}

void find_common()
{
    int len=a.size();
    common=0;
    for(int i=0;i<len;i++) 
        if(a[i]!=b[i]) break;
        else common++;
}

void find_repeated_part_contribution()
{
    ll i=len-1,repeated=1;
    for(;i>common;i--)
    {
        repeated=add(repeated,multiply('9'-a[i],ten_power[len-i-1]));
    }
    i=common;
    repeated=add(repeated,multiply(b[i]-a[i]-1,ten_power[len-i-1]));
    for(i++;i<len;i++)
    {
        repeated=add(repeated,multiply(b[i]-'0',ten_power[len-i-1]));
    }
    for(i=common-1;i>0;i--)
    {
        if(a[i]==a[i-1]) ans=add(ans,multiply(repeated,multiply(a[i]-'0',ten_power[len-i-1])));
    }
}

void find_remaining_part()
{
    ll i=len-1,repeated=1,j;
    // //assume len-common>1
    // char upto='9';
    // for(;a[i]<=upto;a[i]++)
    // {
    //     for(j=i-1;j>=common;j--)
    //     {

    //     }
    // }
    // a[i]='0';
    // propagate(i-1);
    // i--;
    for(;i>common;i--)
    {
        for(;a[i]<='9';a[i]++)
        {
            for(j=i;j>=common;j--)
            {
                if(j>0&&a[j]==a[j-1])
                {
                    ans=add(ans,multiply((a[j]-'0'),ten_power[len-j-1]));
                }
            }
        }
        a[i]='0';
        propagate(i-1);
    }
}

void process()
{
    // make both strings of equal length
    len=b.size();
    make_equal();
    find_common();
    find_repeated_part_contribution();
    find_remaining_part();
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
        process();
        cout<<ans<<' ';
        ans=substract(orig_ans,ans);
        cout<<ans<<'\n';
    }
    return 0;
}
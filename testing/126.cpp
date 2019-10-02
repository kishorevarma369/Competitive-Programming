#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first!=b.first) return a.first<b.first;
    if(a.second!=b.second) return a.second>b.second;
    return 0;
}

bool solve1(vector<pair<ll,ll>> slots,ll expected_coding,ll expected_eating)
{
    sort(slots.begin(),slots.end(),cmp1);
    double max_coding=0,max_eating=0;
    for(int i=0;i<slots.size();i++)
    {
        max_coding+=slots[i].first;
    }
    if(max_coding<expected_coding) return false;
    else if(max_coding==expected_coding)
    {
        if(expected_eating==0) return true;
        return false;
    } 
    ll pres_coding,pres_eating;
    for(int i=0;i<slots.size();i++)
    {
        pres_coding=max_coding-slots[i].first;
        pres_eating=max_eating+slots[i].second;
        if(pres_coding>=expected_coding)
        {
            if(pres_eating>=expected_eating) return true;
            if(pres_coding==expected_coding) return false;
        }
        else{
            auto x=double(expected_coding-pres_coding)/slots[i].first;
            pres_eating+=(1-x)*slots[i].second;
            if(pres_eating>=expected_eating) return true;
            return false;
        }
    }
    return false;
}


int cmp2(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.second!=b.second) return a.second<b.second;
    if(a.first!=b.first) return a.first>b.first;
    return 0;
}

bool solve2(vector<pair<ll,ll>> slots,ll expected_coding,ll expected_eating)
{
    sort(slots.begin(),slots.end(),cmp2);
    double max_coding=0,max_eating=0;
    for(int i=0;i<slots.size();i++)
    {
        max_eating+=slots[i].second;
    }
    if(max_eating<expected_eating) return false;
    else if(max_eating==expected_eating)
    {
        if(expected_eating==0) return true;
        return false;
    } 
    ll pres_coding,pres_eating;
    for(int i=0;i<slots.size();i++)
    {
        pres_coding=max_coding+slots[i].first;
        pres_eating=max_eating-slots[i].second;
        if(pres_eating>=expected_eating)
        {
            if(pres_coding>=expected_coding) return true;
            if(pres_eating==expected_eating) return false;
        }
        else{
            auto x=double(expected_eating-pres_eating)/slots[i].second;
            pres_coding+=(1-x)*slots[i].first;
            if(pres_coding>=expected_coding) return true;
            return false;
        }
    }
    return false;
}



string solve()
{
    ll d,s,coding,eating;
    cin>>d>>s;
    vector<pair<ll,ll>> slots(s);
    string ans="";
    for(int i=0;i<s;i++)
    {
        cin>>slots[i].first>>slots[i].second;
    }
    for(int i=0;i<d;i++)
    {
        cin>>coding>>eating;
        if(solve1(slots,coding,eating)||solve2(slots,coding,eating)) ans.push_back('Y');
        else ans.push_back('N');
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": "<<solve()<<'\n';
    }
    return 0;
}
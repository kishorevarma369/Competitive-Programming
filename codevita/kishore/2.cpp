#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
vector<pair<int,string>> roman_encode={{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};  

string multiply_string(string s,int n)
{
    string ret="";
    for(int i=0;i<n;i++) ret+=s;
    return ret;
}

string get_roman(ll number) 
{ 
    int i=roman_encode.size()-1;    
    string ans="";
    while(number>0) 
    { 
        ans+=multiply_string(roman_encode[i].second,number/roman_encode[i].first); 
        number = number%roman_encode[i].first; 
        i--; 
    } 
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    while(1<=n&&n<=3999)
    {
        auto s=get_roman(n);
        ll mybase=11;
        char max_char=s[0];
        for(auto ch:s) max_char=max(max_char,ch);
        mybase+=max_char-'A';
        n=stoll(s,nullptr,mybase);
    }
    cout<<n<<'\n';
    return 0;
}
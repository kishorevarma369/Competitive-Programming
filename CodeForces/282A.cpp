#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t,x=0;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        if(s=="++X"||s=="X++") x++;
        else x--;
    }
    cout<<x<<'\n';
    return 0;
}

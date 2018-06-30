#include<bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int t,i;
    cin>>t;
    //int a[2][6]={{4,2,4,3,4,3},{1,1,3,3,5,1}};
    regex b("(.*)(101)(.*)"),c("(.*)(010)(.*)");
    while(t--)
    {
        string s;
        cin>>s;
        if(regex_match(s,b)||regex_match(s,c)) cout<<"GOOD\n";
        else cout<<"BAD\n";

    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n;
string solution,s;

void fill_sollution1(char ch1,char ch2)
{
    int k=s.size();
    n--;
    for(int i=0;i<k;i++)
    {
        if(i<n) solution[i]=ch1;
        else solution[i]=ch2;
    }
}

void fill2(int cou,char ch1,char ch2)
{
    for(int i=0;i<cou;i++) solution[i]=ch1;
    int k=n-1;
    for(int i=0;i<k;i++) solution[i+cou]=ch2;
    for(int i=cou+k;i<solution.size();i++) solution[i]=ch1;
}

void perform()
{
    cin>>n>>s;
    solution.resize(s.size());
    if(s[0]!=s.back())
    {
        fill_sollution1(s.back(),s[0]);
        return;
    }
    char cmp;
    if(s[0]=='E') cmp='S';
    else cmp='E';
    int cou=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==cmp)
        {
            if(s[i-1]==cmp)
            {
                fill2(cou,cmp,s[0]);
                return;
            }
            cou++;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        perform();
        cout<<"Case #"<<i<<": "<<solution<<'\n';
    }
    return 0;
}
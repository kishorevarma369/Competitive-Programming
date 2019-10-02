#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<int> v(s.size(),0);
        int i=0;
        int n=s.size();
        for(i=0;i<n;i++)
        {
            if(s[i]!='.')
            {
                auto k=s[i]-'0';
                auto j=i,p=i-k;
                while(j>=p&&j>=0)
                {
                    if(v[j]) goto done;
                    v[j]=1;
                    j--;
                }
                p=i+k;
                j=i+1;
                while(j<=p&&j<n)
                {
                    if(v[j]) goto done;
                    v[j]=1;
                    j++;
                }
            }
        }
        cout<<"safe\n";
        continue;
        done:
        cout<<"unsafe\n";
    }
    return 0;
}
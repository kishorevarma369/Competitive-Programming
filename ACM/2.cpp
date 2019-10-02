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
        int n;
        cin>>n;
        vector<string> v(n);
        for(auto &i:v) cin>>i;
        vector<int> a();
        int k=0,temp1,temp2;
        for(auto &i:v)
        {
            for(auto &j:v)
            {
                if(v[i][j]!='.')
                {
                    temp1=1+(v[i][j]-'0')-j;
                    temp2=1+(v[i][j]-'0')+j;
                }
                if(temp1<=a[k] and temp1>=1)
                    cout<<"unsafe";
                if(temp1<=0)
                    a[k++]=1;
                a[k++]=temp1;
                if(temp2>=50)
                    a[k++]=50;
                a[k++]=temp2;
            }
        }
        cout<<"safe";
    }
    return 0;
}
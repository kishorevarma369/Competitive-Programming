#include<bits/stdc++.h>
using namespace std;
int main(){
    int Q,i,_c=0;
    char ch;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++)
    {
        int n;
        int ar[26]={0};
        cin >> n;
        string b;
        cin >> b;
        _c=0;
        if(n==1)
        {
          if(b[0]=='_') cout<<"YES\n";
          else cout<<"NO\n";
          continue;
        }
        for(i=0;i<n;i++)
        {
          if(b[i]=='_') _c++;
          else
          {
            ar[b[i]-'A']++;
          }
        }
        if(_c)
        {
          for(i=0;i<26;i++)
          {
            if(ar[i]==1)
            {
              break;
            }
          }
          if(i==26) cout<<"YES\n";
          else cout<<"NO\n";
        }
        else
        {
          n--;
          for(i=1;i<n;i++)
          {
            if(b[i]==b[i+1]||b[i]==b[i-1]);
            else break;
          }
          if(i==n)
          {
            if(b[0]==b[1]&&b[n]==b[n-1])
            {
              cout<<"YES\n";
              continue;
            }
          }
          cout<<"NO\n";
        }
    }
    return 0;
}

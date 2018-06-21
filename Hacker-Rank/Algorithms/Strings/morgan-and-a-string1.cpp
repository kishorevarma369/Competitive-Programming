#include <bits/stdc++.h>

using namespace std;

string morganAndString(string a, string b)
{
    //string c(a.size()+b.size());
    char c[a.size()+b.size()+5];
    int i=0,j=0,k=0,l,m,flag,p,q;
    for(;i<a.size()&&j<b.size();k++)
    {
      if(a[i]==b[j])
      {
        l=i+1;
        m=j+1;
        for(;;l++,m++)
        {
          if(l<a.size()&&m<b.size())
          {
            if(a[l]==b[m])
            {
              if(a[i]<a[l])
              {
                flag=0;
                break;
              }
            }
            else if(a[l]>b[m])
            {
               flag=1;
               break;
            }
            else
            {
              flag=0;
              break;
            }
          }
          else if(l==a.size()&&m==b.size())
          {
            flag=0;
            break;
          }
          else
          {
            if(l==a.size())
            {
              if(a[i]>b[m])
              {
                flag=1;
              }
              else flag=0;
            }
            else if(m==b.size())
            {
              if(a[l]<b[j])
              {
                flag=0;
              }
              else flag=1;
            }
            break;
          }
        }
        if(flag==0) c[k]=a[i++];
        else c[k]=b[j++];
      }
      else if(a[i]>b[j])
      {
          c[k]=b[j++];
      }
      else
      {
          c[k]=a[i++];
      }
    }
    //cout<<"i="<<i<<" j="<<j<<" k="<<k<<'\n';
    if(i==a.size())
    {
      for(;j<b.size();j++,k++)
      {
        c[k]=b[j];
      }
    }
    if(j==b.size())
    {
      for(;i<a.size();i++,k++)
      {
        c[k]=a[i];
      }
    }
    //cout<<"i="<<i<<" j="<<j<<" k="<<k<<'\n';
    c[k]=0;
    return string(c);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string a;
        cin >> a;
        string b;
        cin >> b;
        string result = morganAndString(a, b);
        cout << result << endl;
    }
    return 0;
}

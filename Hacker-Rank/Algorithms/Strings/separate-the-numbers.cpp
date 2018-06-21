#include <bits/stdc++.h>

using namespace std;

int inr(char *s)
{
  int i=0,j=0,carry=1,k=0;
  j=strlen(s);
  while(i<j)
  {
    k=s[i]-'0'+carry;
    carry=0;
    if(k>9) carry=(k/10);
    s[i]=(k%10)+'0';
    i++;
  }
  while(carry!=0)
  {
      if(carry>9)
      {
        s[i++]=(carry%10)+'0';
        carry/=10;
      }
      else
      {
        s[i++]=carry+'0';
        break;
      }
  }
  s[i]='\0';
  return i;
}

void separateNumbers(string s)
{
       char va[1000];
       int i,j,k,l,p,q,flag=0;
       for(k=1;k<s.size();k++)
       {
         j=0;
         for(i=k-1;i>=0;i--)
         {
           va[j++]=s[i];
         }
         while(j>=1)
         {
           if(va[j-1]=='0') j--;
           else break;
         }
         va[j]=0;
         l=inr(va);
         p=l-1;
         for(i=k;i+p<s.size();)
         {
             for(;p>=0;)
             {
               if(s[i]!=va[p]) goto b;
               p--;
               i++;
             }
             if(i==s.size())
             {
               flag=1;
               break;
             }
             l=inr(va);
             p=l-1;
         }
         b:
         if(flag==1)
         {
           cout<<"YES ";
           for(i=0;i<k;i++) cout<<s[i];
           cout<<'\n';
           return;
         }
       }
       cout<<"NO\n";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        separateNumbers(s);
    }
    return 0;
}

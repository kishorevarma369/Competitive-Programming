#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> s={ "Beginner", "Junior Developer", "Middle Developer", "Senior Developer", "Hacker", "Jeff Dean"};
    int n,i,j,k,count=0;
    cin >> n ;
    for(i=0;i<n;i++)
    {
      count=0;
      for(j=0;j<5;j++)
      {
        cin >> k;
        if(k) count++;
      }
      cout<<s[count]<<'\n';

    }
    return 0;
}

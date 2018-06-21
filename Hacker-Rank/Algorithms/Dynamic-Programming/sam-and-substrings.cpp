#include <bits/stdc++.h>

using namespace std;
/*
//time limit exceeded dynamic programming
int substrings(string balls)
{
    vector<unsigned long long int> table(balls.size(),0);
    unsigned long long int size=balls.size(),lim,i,j,k,sum=0,con=1e9+7;
    for(i=1;i<=size;i++)
    {
      k=i-1;
      for(j=0;k<size;j++,k++)
      {
        table[j]=(table[j]*10+balls[k]-'0')%con;
        sum=(sum+table[j])%con;
      }
    }
    return sum;
}
*/


unsigned long long int substrings(string balls)
{
    int size=balls.size(),i;
    unsigned long long k=1,sum=0,con=1e9+7;
    for(i=size-1;i>=0;i--)
    {
      sum=(sum+(i+1)*k*(balls[i]-'0'))%con;
      k=(k*10+1)%con;
    }
    return sum;
}

int main() {
    string balls;
    cin >> balls;
    cout << substrings(balls);
    return 0;
}

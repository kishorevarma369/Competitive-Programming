#include <bits/stdc++.h>

using namespace std;

string solve(int year)
{
    int mon;
    if(year<1918)
    {
      if(year%4==0)
      {
        cout<<"12.09."<<year;
      }
      else cout<<"13.09."<<year;
    }
    else if(year==1918)
    {
      cout<<"26.09.1918";
    }
    else
    {
      if(year%100==0)
      {
        if(year%400==0) cout<<"12.09."<<year;
        else cout<<"13.09."<<year;
      }
      else if(year%4==0)
      {
        cout<<"12.09."<<year;
      }
      else cout<<"13.09."<<year;
    }
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}

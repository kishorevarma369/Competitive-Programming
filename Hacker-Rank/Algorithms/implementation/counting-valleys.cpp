#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s)
{
    int pos=0,valcount=0;
    for(auto i:s)
    {
      if(i=='U')
      {
        pos++;
        if(pos==0) valcount++;
      }
      else
      {
        pos--;
      }
    }
    return valcount;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = countingValleys(n, s);
    cout << result << endl;
    return 0;
}

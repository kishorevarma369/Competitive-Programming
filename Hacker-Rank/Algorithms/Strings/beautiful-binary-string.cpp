#include <bits/stdc++.h>

using namespace std;

int beautifulBinaryString(string b)
{
  int i,count=0;
  for(i=0;i+2<b.size();i++)
  {
    if(b[i]=='0'&&b[i+1]=='1'&&b[i+2]=='0')
    {
      i+=2;
      b[i]='1';
      count++;
    }
  }
  return count;
}

int main() {
    int n;
    cin >> n;
    string b;
    cin >> b;
    int result = beautifulBinaryString(b);
    cout << result << endl;
    return 0;
}

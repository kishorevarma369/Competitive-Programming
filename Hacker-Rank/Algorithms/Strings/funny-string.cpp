#include <bits/stdc++.h>

using namespace std;

string funnyString(string s)
{
  int i=1,j=s.size()-1;
  while(i<=j)
  {
    if(abs(s[i]-s[i-1])!=abs(s[j]-s[j-1])) return string("Not Funny");
    i++;
    j--;
  }
  return string("Funny");
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string result = funnyString(s);
        cout << result << endl;
    }
    return 0;
}

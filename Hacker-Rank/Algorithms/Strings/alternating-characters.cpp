#include <bits/stdc++.h>

using namespace std;

int alternatingCharacters(string s)
{
      int count=0,i,prev=s[0];
      for(i=1;i<s.size();i++)
      {
        if(s[i]==prev) count++;
        else prev=s[i];
      }
      return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = alternatingCharacters(s);
        cout << result << endl;
    }
    return 0;
}

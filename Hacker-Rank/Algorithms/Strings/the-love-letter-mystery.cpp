#include <bits/stdc++.h>

using namespace std;

int theLoveLetterMystery(string s)
{
    int i=0,j=s.size()-1,count=0;
    while(i<j)
    {
      count+=abs(s[i]-s[j]);
      i++;
      j--;
    }
    return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = theLoveLetterMystery(s);
        cout << result << endl;
    }
    return 0;
}

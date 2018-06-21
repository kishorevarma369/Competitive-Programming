#include <bits/stdc++.h>

using namespace std;

long repeatedString(string s, long n) {
    int size=s.size(),i;
    vector<int> v(size+1,0);
    for(i=0;i<size;i++)
    {
      v[i+1]=v[i];
      if(s[i]=='a') v[i+1]++;
    }
    return (n/size)*v[size]+v[n%size];
}

int main() {
    string s;
    cin >> s;
    long n;
    cin >> n;
    long result = repeatedString(s, n);
    cout << result << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long int utopianTree(int n)
{
    if(n==0) return 1;
    if(n&1)
    {
      n++;
      return pow(2,n/2+1)-2;
    }
    return pow(2,n/2+1)-1;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << utopianTree(n) << endl;
    }
    return 0;
}

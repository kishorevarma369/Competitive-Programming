#include <bits/stdc++.h>

using namespace std;

int stringConstruction(string s) {
    vector<int> index(26,0);
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        if(!index[s[i]-'a'])
        {
            count++;
            index[s[i]-'a']++;
        }
    }
    return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = stringConstruction(s);
        cout << result << endl;
    }
    return 0;
}

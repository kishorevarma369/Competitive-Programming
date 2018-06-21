#include <bits/stdc++.h>

using namespace std;

string twoStrings(string s1, string s2)
{
    vector<int> index1(26,0),index2(26,0);
    for(int i=0;i<s1.size();i++)
    {
        index1[s1[i]-'a']++;
    }
    for(int i=0;i<s2.size();i++)
    {
        if(index1[s2[i]-'a'])
        {
            return string("YES");
        }
    }
    return string("NO");
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        string result = twoStrings(s1, s2);
        cout << result << endl;
    }
    return 0;
}

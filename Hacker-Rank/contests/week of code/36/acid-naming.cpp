/*
https://www.hackerrank.com/contests/w36/challenges/acid-naming/problem

*/

#include <bits/stdc++.h>

using namespace std;

string acidNaming(string acid_name) {
    char s[]="hydro",s1[]="ic";
    int j=0,i=0;
    string res;
    i=acid_name.size();
    i-=2;
    if(acid_name[i]=='i'&&acid_name[i+1]=='c')
    {
        if(i>=5)
        {
               for(j=0;s[j]!=0;j++)
               {
                   if(acid_name[j]!=s[j]) break;
               }
            if(s[j]==0) res="non-metal acid";
            else res="polyatomic acid";
        }
        else res="polyatomic acid";
    }
    else res="not an acid";

    return res;
}

int main() {
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string acid_name;
        cin >> acid_name;
        string result = acidNaming(acid_name);
        cout << result << endl;
    }
    return 0;
}

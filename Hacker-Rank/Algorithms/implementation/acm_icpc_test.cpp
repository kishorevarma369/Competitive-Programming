#include <bits/stdc++.h>

using namespace std;

unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

vector <int> acmTeam(vector <string> &a) {
    vector<int> v;
    int i,j,ssize=a[0].size(),cou=0,mymax=0,val,k;
    for(i=0;i<a.size();i++)
    {
        for(j=i+1;j<a.size();j++)
        {
            val=0;
            for(k=0;k<ssize;k++)
            {
                val+=(a[i][k]-'0')|(a[j][k]-'0');
            }
            if(val>mymax)
            {
                mymax=val;
                cou=1;
            }
            else if(val==mymax)
            {
                cou++;
            }
        }
    }
    v.push_back(mymax);
    v.push_back(cou);
    return v;
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0; topic_i < n; topic_i++){
       cin >> topic[topic_i];
    }
    vector <int> result = acmTeam(topic);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}

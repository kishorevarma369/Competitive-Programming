#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<int>  split(const std::string& str) {
    vector<int> v;
  stringstream ss(str);
  ss >> std::noskipws;
  int field;
  char ws_delim;
  while(1) {
    if( ss >> field )
      v.push_back(field);
    else if (ss.eof())
      break;
    ss.clear();
    ss >> ws_delim;
  }
  return v;
}
int main()
{
    string s;
    // while(1)
    // {
    //     cin>>s;
    //     auto l=split(s);
    //     for(auto val:l) cout<<val<<'\n';
    // }
    cin >> noskipws >> s;
    cout<<s<<'\n';
    return 0;
}
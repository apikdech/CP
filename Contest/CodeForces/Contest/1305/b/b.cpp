/**
 * author:  apikdech
 * created: 03.03.2020 21:45:40
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  vector<vector<int>> ans;
  while(true) {
    int ok = 0;
    int l = 0, r = s.length() - 1;
    vector<int> v;
    while(l < r) {
      while(s[l] == ')') l++;
      while(s[r] == '(') r--;
      if (l < r) {
        v.push_back(l);
        v.push_back(r);
        s[l] = s[r] = '*';
        ok = 1;
      }
      l++, r--;
    }
    if (ok) {
      sort(v.begin(), v.end());
      string t = "";
      for (char c : s) if (c != '*') t += c;
      s = t;
      ans.push_back(v);
    }
    else break;
  }
  cout << ans.size() << "\n";
  for (auto it : ans) {
    cout << it.size() << "\n";
    for (int i = 0; i < it.size(); i++) {
      cout << it[i] + 1 << " \n"[i + 1 == it.size()];
    }
  }
  return 0;
}

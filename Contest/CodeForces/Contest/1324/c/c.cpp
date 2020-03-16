/**
 * author:  apikdech
 * created: 12.03.2020 20:26:41
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    string s;
    int ans = 0, prv = 0;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if (c == 'R') v.push_back(i + 1);
    }
    for (int &num : v) {
      ans = max(ans, num - prv);
      prv = num;
    }
    if (prv) ans = max(ans, (int)s.length() + 1 - prv);
    if (!ans) ans = s.length() + 1;
    cout << ans << "\n";
  }
  return 0;
}

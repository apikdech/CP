/**
 * author:  apikdech
 * created: 29.01.2020 21:49:45
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
    string s, t;
    int ans = 1, lst = -1, ok = 1;
    cin >> s >> t;
    vector<int> idx[30]; 
    int cnt[30];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < s.length(); i++) {
      idx[s[i] - 'a'].push_back(i);
      cnt[s[i] - 'a']++;
    }
    for (char &c : t) {
      if (!cnt[c - 'a']) {
        ok = 0;
        break;
      }
      auto pos = lower_bound(idx[c - 'a'].begin(), idx[c - 'a'].end(), lst);
      if (pos == idx[c - 'a'].end()) {
        lst = -1;
        ans++;
        pos = lower_bound(idx[c - 'a'].begin(), idx[c - 'a'].end(), lst);
      }
      lst = *pos;
      lst++;
    }
    if (ok) cout << ans << "\n";
    else cout << "-1\n";
  }
  return 0;
}

/**
 * author:  apikdech
 * created: 17.02.2020 23:03:28
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

ll cnt[26], ans = 0, pref[N][26];
map<pair<int, int>, ll> m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
    for (int j = 0; j < 26; j++) {
      if (i) pref[i][j] = pref[i-1][j];
      if (s[i] - 'a' == j) pref[i][j]++;
    }
  }
  for (int i = 0; i < 26; i++) {
    ans = max(ans, cnt[i]);
    ans = max(ans, cnt[i] * (cnt[i] - 1)/2);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      m[{j, s[i] - 'a'}] += pref[i-1][j];
    }
  }
  for (auto it : m) {
    ans = max(ans, it.second);
  }
  cout << ans << "\n";
  return 0;
}

/**
 * author:  apikdech
 * created: 15.03.2020 22:25:16
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int cnt[60];
vector<ll> ans;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll u, v;
  cin >> u >> v;
  if (u > v || abs(u - v) & 1) return cout << "-1\n", 0;
  for (int i = 0; i < 60; i++) {
    if (u & 1LL << i) cnt[i]++;
    if ((v-u)/2 & 1LL << i) cnt[i] += 2;
  }
  for (int it = 0; it < 3; it++) {
    ll num = 0;
    for (int i = 0; i < 60; i++) {
      if (cnt[i]) {
        num += 1LL << i;
        cnt[i]--;
      }
    }
    if (num) ans.push_back(num);
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
  return 0;
}

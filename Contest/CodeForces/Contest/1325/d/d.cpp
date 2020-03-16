/**
 * author:  apikdech
 * created: 14.03.2020 23:30:58
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

vector<ll> ans;
int cnt[62];

vector<ll> to_bin(ll x) {
  vector<ll> res;
  while(x) {
    res.push_back(x % 2);
    x /= 2;
  }
  while(res.size() < 60) res.push_back(0);
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll u, v;
  cin >> u >> v;
  if (u > v || abs(u - v) & 1) return cout << "-1\n", 0;
  vector<ll> x = to_bin(u);
  vector<ll> y = {v};
  while(y.size() < 60) y.push_back(0);
  for (int i = 0; i < 60; i++) {
    if (u & 1LL << i) cnt[i]++;
  }
  for (int i = 0; i < 60; i++) {
    if (y[i] == x[i]) continue;
    if ((y[i] - x[i]) & 1) cnt[i-1] += 2, y[i]--;
    y[i+1] += (y[i] - x[i])/2;
  }
  for (int it = 0; it < 60; it++) {
    ll num = 0;
    for (int i = 0; i < 60; i++) {
      if (cnt[i]) {
        cnt[i]--;
        num += 1LL << i;
      }
    }
    if (num) ans.push_back(num);
  }
  ll sor = 0, sum = 0;
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i + 1 == ans.size()];
    sor ^= ans[i];
    sum += ans[i];
  }
  // cout << sor << " " << sum << "\n";

  return 0;
}

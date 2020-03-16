/**
 * author:  apikdech
 * created: 04.02.2020 22:18:36
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll a, b, k;
  cin >> n >> a >> b >> k;
  vector<ll> v;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ll l = 0, r = 1e9, dif = 0;
    while(l <= r) {
      ll m = (l + r) >> 1;
      ll health = x - m * b;
      ll me = (health + a - 1)/ a;
      if (me > m) l = m + 1, dif = me - m - 1;
      else r = m - 1;
    }
    v.push_back(dif);
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (ll &it : v) {
    if (k >= it) k -= it, ans++;
  }
  cout << ans << "\n";
  return 0;
}

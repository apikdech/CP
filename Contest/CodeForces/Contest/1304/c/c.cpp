/**
 * author:  apikdech
 * created: 15.02.2020 20:43:42
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

void solve() {
  int n, init;
  cin >> n >> init;
  int l = init, r = init, t = 0, ok = 1;
  for (int i = 0; i < n; i++) {
    int now, lo, hi;
    cin >> now >> lo >> hi;
    if (!ok) continue;
    if (r < lo) {
      if (lo - r > now - t) ok = 0;
      r = min(r + now - t, hi);
      l = lo;
    } else if (l > hi) {
      if (l - hi > now - t) ok = 0;
      l = max(lo, l - now + t);
      r = hi;
    } else {
      l = max(l, lo);
      r = min(r, hi);
      l = max(lo, l - now + t);
      r = min(hi, r + now - t);
    }
    t = now;
  }
  if (!ok) cout << "NO\n";
  else cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}

/**
 * author:  apikdech
 * created: 07.03.2020 16:46:16
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 4e4 + 5;

ll a[N], b[N], pref[N][2];
ll n, m, k, ans = 0;

ll cek(int r, int c) {
  ll res = 0, freq = 0;
  for (int i = 1; i <= m; i++) {
    if (i + c  - 1 > m) break;
    if (pref[c + i - 1][1] - pref[i - 1][1] == c) freq++;
  }
  for (int i = 1; i <= n; i++) {
    if (i + r - 1 > n) break;
    if (pref[r + i - 1][0] - pref[i - 1][0] == r) res += freq;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i][0] = pref[i-1][0] + a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    pref[i][1] = pref[i-1][1] + b[i];
  }
  for (int i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      ans += cek(k/i, i);
      if (i * i != k) ans += cek(i, k/i);
    }
  }
  cout << ans << "\n";
  return 0;
}

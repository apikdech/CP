/**
 * author:  apikdech
 * created: 27.12.2019 21:48:57
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int a[N], pref[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	int t;
  cin >> t;
  while(t--) {

    int n, ans = 0, mx = 0, cnt = 0, idx = 0;
    ll s, sum = 0, cur = 0;
    cin >> n >> s;
    for (int i = 0; i <= n; i++) pref[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      pref[i] = pref[i-1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
      cur += a[i];
      if (a[i] > mx) mx = a[i], idx = i;
      if (cur > s && cur - mx <= s) {
        if (cnt < i) cnt = i, ans = idx;
      }
    }
    if (sum <= s) cout << "0\n";
    else cout << ans << "\n";
  }
  return 0;
}

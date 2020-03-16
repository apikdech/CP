/**
 * author:  apikdech
 * created: 13.02.2020 21:50:39
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, ans = 0, k = 0, l = 1e9, r = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a[0] = a[1], a[n+1] = a[n];
    for (int i = 1; i <= n; i++) {
      if ((a[i-1] < 0 || a[i+1] < 0) && ~a[i]) l = min(l, a[i]), r = max(r, a[i]);
      if (i > 1 && a[i] >= 0 && a[i-1] >= 0) ans = max(ans, abs(a[i] - a[i-1]));
    }
    k = (l + r + 1) >> 1;
    ans = max({ans, r - k, k - l});
    cout << ans << " " << k << "\n";
  }
  return 0;
}

/**
 * author:  apikdech
 * created: 22.01.2020 23:17:44
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, ans = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 0; j < m; j++) {
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      if (a[i][j] % m == (j + 1) % m && a[i][j] <= n * m) cnt[(n + (i - (a[i][j]-1)/m)) % n]++;
    }
    int mn = n;
    for (int i = 0; i <= n; i++) {
      // cout << i << " " << cnt[i] << "\n";
      mn = min(mn, n - cnt[i] + i);
      // mn = max(mn, 0);
    }
    // cout << mn << " z\n";
    ans += mn;
  }
  cout << ans << "\n";
  return 0;
}

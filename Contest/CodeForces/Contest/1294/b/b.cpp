/**
 * author:  apikdech
 * created: 22.01.2020 21:45:04
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1005;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, ok = 1, x = 0, y = 0;
    string ans = "";
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[l, r] : a) {
      cin >> l >> r;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      if (x > a[i].first || y > a[i].second) ok = 0;
      int dx = a[i].first - x;
      int dy = a[i].second - y;
      if (!ok) break;
      ans += string(dx, 'R');
      ans += string(dy, 'U');
      x = a[i].first;
      y = a[i].second;
    }
    if (!ok) cout << "NO\n";
    else {
      cout << "YES\n";
      cout << ans << "\n";
    }
  }
  return 0;
}

/**
 * author:  apikdech
 * created: 24.02.2020 06:08:44
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    ll a, b, x, y, ans = 0;
    cin >> a >> b >> x >> y;
    ans = max(ans, x * b);
    ans = max(ans, a * y);
    ans = max(ans, (a - x - 1) * b);
    ans = max(ans, (b - y - 1) * a);
    cout << ans << "\n";
  }
  return 0;
}

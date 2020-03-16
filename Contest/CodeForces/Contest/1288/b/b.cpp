/**
 * author:  apikdech
 * created: 14.01.2020 23:27:43
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
    ll a, b, x = 1, ans = 0;
    cin >> a >> b;
    for (int i = 0; i < 10; i++) {
      x *= 10;
      if (x - 1 <= b) ans += a;
    }
    cout << ans << "\n";
  }
  return 0;
}

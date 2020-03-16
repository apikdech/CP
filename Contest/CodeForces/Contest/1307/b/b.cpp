/**
 * author:  apikdech
 * created: 17.02.2020 22:44:30
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
    int n;
    ll x, mx = 0, ok = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      if (a == x) ok = 1;
      mx = max(mx, a);
    }
    if (ok) cout << "1\n";
    else if (mx > x) cout << 2 << "\n";
    else cout << (x + mx - 1)/mx << "\n";
  }
  return 0;
}

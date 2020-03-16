/**
 * author:  apikdech
 * created: 02.03.2020 12:38:55
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

ll a[N], ans = 0;
map<ll, ll> m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    m[x - i] += x;
  }
  for (auto &[num, val] : m) ans = max(ans, val);
  cout << ans << "\n";
  return 0;
}

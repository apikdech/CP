/**
 * author:  apikdech
 * created: 15.02.2020 20:05:16
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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    y -= x;
    a += b;
    if (y % a) cout << "-1\n";
    else cout << y/a << "\n";
  }
  return 0;
}

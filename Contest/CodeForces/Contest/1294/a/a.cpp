/**
 * author:  apikdech
 * created: 22.01.2020 21:37:49
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
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int mx = 0;
    mx = max({a, b, c});
    n -= mx - a;
    n -= mx - b;
    n -= mx - c;
    if (n < 0 || n % 3) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}

/**
 * author:  apikdech
 * created: 12.02.2020 21:44:11
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
    ll n, g, b;
    cin >> n >> g >> b;
    ll req = ((n + 1)/2 + g - 1)/g;
    ll kurang = (n + 1)/2 - (req - 1) * g;
    ll ans = (req - 1) * b;
    ans += (req - 1) * g + kurang;
    cout << max(ans, n) << "\n";
  }
  return 0;
}

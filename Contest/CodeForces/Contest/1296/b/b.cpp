/**
 * author:  apikdech
 * created: 04.02.2020 21:41:35
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
    ll n, ans = 0;
    cin >> n;
    ans = n;
    while(n >= 10) {
      ans += n / 10;
      n += n/10 - n/10 * 10;
    }
    cout << ans << "\n";
  }
  return 0;
}

/**
 * author:  apikdech
 * created: 29.12.2019 00:13:25
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
    int n, k;
    cin >> n >> k;
    if (n < k) cout << min(n, k/2) << "\n";
    else if (n % k == 0) cout << n << "\n";
    else {
      int ans = n/k*k;
      n -= ans;
      ans += min(n, k/2);
      cout << ans << "\n";
    }
  }
  return 0;
}

/**
 * author:  apikdech
 * created: 09.02.2020 21:11:27
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
    int n, sum = 0, zero = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      sum += x;
      if (x == 0) zero++;
    }
    sum += zero;
    ans += zero;
    if (sum == 0) ans++;
    cout << ans << "\n";
  }
  return 0;
}

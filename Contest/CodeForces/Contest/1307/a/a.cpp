/**
 * author:  apikdech
 * created: 17.02.2020 22:37:38
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
    int n, d, ans = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (!i) ans = x;
      else {
        int res = 0;
        for (int j = 0; j <= x; j++) {
          if (j * i <= d) res = j;
        }
        ans += res;
        d -= res * i;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

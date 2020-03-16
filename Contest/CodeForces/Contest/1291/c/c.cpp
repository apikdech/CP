/**
 * author:  apikdech
 * created: 02.02.2020 22:12:05
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 3505;

int a[N];
int n, m, k;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    if (k >= m) {
      k = min(k, m);
      for (int i = 0; i < k; i++) {
        ans = max(ans, a[i]);
      }
      for (int i = n - 1; i > n - k - 1; i--) {
        ans = max(ans, a[i]);
      }
    } else {
      for (int i = 0; i < k + 1; i++) {
        int tmp = 2e9;
        for (int j = i; j < i + m - k; j++) {
          tmp = min(tmp, max(a[j], a[j + n - m]));
        }
        ans = max(ans, tmp);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

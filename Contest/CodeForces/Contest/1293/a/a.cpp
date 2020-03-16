/**
 * author:  apikdech
 * created: 19.01.2020 20:35:17
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
    int n, s, k, ans = 2e9;
    cin >> n >> s >> k;
    unordered_map<int, int> m;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      m[x]++;
    }
    for (int i = 0; i < 2000; i++) {
      if (s + i > n) break;
      if (!m[i + s]) ans = min(ans, i);
    }
    for (int i = 0; i < 2000; i++) {
      if (s - i <= 0) break;
      if (!m[s - i]) ans = min(ans, i);
    }
    cout << ans << "\n";
  }
  return 0;
}

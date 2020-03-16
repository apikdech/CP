/**
 * author:  apikdech
 * created: 24.02.2020 06:17:12
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, INF = 1e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int a[2], p;
    cin >> a[0] >> a[1] >> p;
    string s;
    cin >> s;
    int n = s.length();
    vector<int> prv(n + 1), nxt(n + 1), dp(n + 1, INF), vis(n);
    int now = s[0] - 'A', idx = 0, ans = n - 1;
    for (int i = 0; i < n; i++) {
      if (s[i] - 'A' == now) prv[i] = idx;
      else nxt[idx] = i, prv[i] = idx, idx = i, now = s[i] - 'A';
    }
    if (!nxt[idx]) nxt[idx] = n-1, prv[n-1] = idx;
    dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
      int cost = a[s[i] - 'A'];
      int nx = max(nxt[prv[i]], nxt[i]);
      dp[i] = min(dp[i], dp[nx] + cost);
    }
    for (int i = 0; i < n; i++) {
      if (dp[i] <= p) ans = min(ans, i);
    }
    cout << ans + 1 << "\n";
  }
  return 0;
}

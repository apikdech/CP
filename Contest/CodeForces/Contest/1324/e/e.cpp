/**
 * author:  apikdech
 * created: 12.03.2020 21:01:32
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2005;

int a[N], ans = 0;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, h, l, r, sum = 0;
  cin >> n >> h >> l >> r;
  vector<int> dp(N, -N);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vector<int> next_dp(N, -N);
    for (int j = 0; j < h; j++) {
      for (int k = 0; k < 2; k++) {
        int now = a[i] + j - k;
        while(now >= h) now -= h;
        if (l <= now && now <= r) next_dp[now] = max(next_dp[now], dp[j] + 1);
        else next_dp[now] = max(next_dp[now], dp[j]);
      }
    }
    dp = next_dp;
  }
  for (int i = 0; i < N; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
  return 0;
}

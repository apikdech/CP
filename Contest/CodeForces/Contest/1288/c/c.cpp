/**
 * author:  apikdech
 * created: 15.01.2020 00:12:24
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2005;

ll ans = 0, ncr[N][N], dp[N][N];

void pre() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == j || i == 0 || j == 0) ncr[i][j] = 1LL;
      else ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % MOD;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pre();
  int n, m;
  cin >> n >> m;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = i; j <= n; j++) {
  //     ans = (ans + ncr[i + m - 2][m - 1] * ncr[n - j + m - 1][m - 1] % MOD) % MOD;
  //   }
  // }
  ans = ncr[n + 2*m - 1][2*m];
  cout << ans << "\n";
  return 0;
}

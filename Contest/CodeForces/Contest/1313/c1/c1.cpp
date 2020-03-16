/**
 * author:  apikdech
 * created: 23.02.2020 16:33:33
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1005;

int m[N], dp[N], ans[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m[i];
  }
  for (int i = 1; i <= n; i++) {
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i + 1 == n];
  }
  return 0;
}

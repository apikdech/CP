/**
 * author:  apikdech
 * created: 03.03.2020 23:45:08
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 5005;

ll f[N];
int ans[N];

void pre() {
  int cnt = 2;
  f[3] = 1;
  f[4] = 2;
  for (int i = 5; i < N; i++) {
    f[i] = f[i-1] + cnt;
    if (i % 2 == 0) cnt++;
  }

}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, lst;
  cin >> n >> m;
  pre();
  if (f[n] < m) cout << "-1\n";
  else {
    for (int i = 1; i <= n; i++) {
      ans[i] = i;
      if (f[i] <= m) lst = i;
      else ans[i] += 1e8 + 1 + 1e4 * i;
    }
    if (f[lst] < m) {
      lst++;
      ans[lst] = ans[lst - 1] + ans[lst - 2 * (m - f[lst - 1])];

    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
  return 0;
}

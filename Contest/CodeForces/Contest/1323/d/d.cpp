/**
 * author:  apikdech
 * created: 07.03.2020 17:31:16
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 4e5 + 5;

int cnt[N][30], ans = 0, carry[30], a[N], res[30], p[N][30];

void pre() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 30; j++) {
      p[i][j] = j;
    }
  }
}

int f(int v, int pos) {
  return (v == p[pos][v] ? v : p[pos][v] = f(p[pos][v], pos));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  pre();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j < 30; j++) {
      if (a[i] & 1 << j) cnt[i][j] = cnt[i-1][j] + 1;
      else cnt[i][j] = cnt[i-1][j];
      if (j && a[i] & 1 << j && a[i] & 1 << (j - 1)) 
        p[i][j-1] = j;
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j < 30; j++) {
  //     cout << cnt[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      cout << f(j, i) << " ";
    }
    cout << "\n";
  }
  for (int j = 0; j < 30; j++) {
    for (int i = 1; i <= n; i++) {
      if (a[i] & 1 << j) {
        res[j] += n - i - (cnt[n][j] - cnt[i][j]);
        int nxt = f(j, i) + 1;
        carry[nxt] += cnt[n][j] - cnt[i][j];
      } else {
        res[j] += cnt[n][j] - cnt[i][j];
      }
    }
  }
  for (int i = 0;  i < 30; i++) cout << res[i] << " " << carry[i] << "\n";
  for (int i = 0; i < 30; i++) {
    if ((res[i] + carry[i]) & 1) ans += 1 << i;
  }
  cout << ans << "\n";
  return 0;
}

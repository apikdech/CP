/**
 * author:  apikdech
 * created: 20.01.2020 13:08:50
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int a[N], vis[N], l, r, cnt[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = -1; j <= 1; j++) {
      if (!cnt[i]) break;
      if (vis[i + j]) continue;
      vis[i + j] = 1;
      cnt[i]--;
      r++;
    }
  }
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!cnt[i]) continue;
    l++, i += 2;
  }
  cout << l << ' ' << r << '\n';
  return 0;
}

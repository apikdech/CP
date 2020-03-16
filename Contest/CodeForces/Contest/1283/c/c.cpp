/**
 * author:  apikdech
 * created: 29.12.2019 00:21:44
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int ans[N], vis[N], idx = N, ok = 1, lst;
set<int> s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ans[i];
    if (ans[i]) vis[ans[i]] = 1;
    else idx = min(idx, i);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) s.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i]) continue;
    if (*s.begin() != i) ans[i] = *s.begin(), s.erase(*s.begin());
    else if (s.size() > 1) ans[i] = *s.rbegin(), s.erase(*s.rbegin());
    else ok = 0, lst = i;
  }
  if (!ok) {
    ans[lst] = *s.begin();
    swap(ans[lst], ans[idx]);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
  return 0;
}

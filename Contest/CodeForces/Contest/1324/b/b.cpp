/**
 * author:  apikdech
 * created: 12.03.2020 20:11:05
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 5005, INF = 5005;

int l[N], r[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, ok = 0;
    cin >> n;
    for (int i = 0; i <= n; i++) l[i] = INF, r[i] = -1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      l[x] = min(l[x], i);
      r[x] = max(r[x], i);
    }
    for (int i = 1; i <= n; i++) {
      if (r[i] - l[i] > 1) ok = 1;
    }
    if (!ok) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}

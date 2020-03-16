/**
 * author:  apikdech
 * created: 24.02.2020 06:49:57
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
    int n;
    cin >> n;
    vector<int> a(n << 3), b(n + 1), vis(n << 3);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      a[2*i - 1] = b[i];
      vis[b[i]] = 1;
    }
    n <<= 1;
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i]) continue;
      int nxt = 0;
      for (int j = a[i-1]; j <= n; j++) {
        if (vis[j]) continue;
        nxt = j;
        break;
      }
      if (nxt) vis[nxt] = 1, a[i] = nxt;
      else ok = 0;
    }
    if (!ok) cout << "-1\n";
    else for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
  }
  return 0;
}

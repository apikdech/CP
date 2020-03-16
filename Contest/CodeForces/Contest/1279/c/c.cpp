/**
 * author:  apikdech
 * created: 27.12.2019 22:20:52
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int a[N], b[N], idx[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
  cin >> t;
  while(t--) {
    int n, m, fi = 0, la = 0;
    ll ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      idx[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      if (idx[b[i]] <= fi) ans++;
      else ans += 2*(idx[b[i]] - la) + 1;
      la++;
      fi = max(fi, idx[b[i]]);
      // cout << fi << " " << la << " " << ans << "\n";
    }
    cout << ans << "\n";
  }
	return 0;
}

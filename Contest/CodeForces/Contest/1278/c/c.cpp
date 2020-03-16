/**
 * author:  apikdech
 * created: 19.12.2019 22:25:40
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

int a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, r = 0, b = 0;
		cin >> n;
		int ans = 2*n;
		for (int i = 0; i < 2*n; i++) {
			cin >> a[i];
		}
		map<pair<int, int>, int> m;
		for (int i = 2*n - 1; i >= n; i--) {
			if (a[i] == 1) r++;
			else b++;
			int mn = min(r, b);
			if (m.count({r - mn, b - mn})) m[{r - mn, b - mn}] = min(i, m[{r - mn, b - mn}]);
			else m[{r - mn, b - mn}] = i;
		}
		r = b = 0;
		if (m.count({0, 0})) ans = m[{0, 0}];
		// cout << ans << "\n";
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) r++;
			else b++;
			int eq = max(r, b);
			if (r == b) ans = min(ans, 2*n - i - 1);
			if (m.count({eq - r, eq - b}) == 0) continue;
			ans = min(ans, m[{eq - r, eq - b}] - i - 1);
			// cout << r << " " << b << " " << i << " " << m[{eq - r, eq - b}] << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}

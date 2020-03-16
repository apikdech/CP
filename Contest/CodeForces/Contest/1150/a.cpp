#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	int n, m, r, mn = 1e5, mx = 0, ans;
	cin >> n >> m >> r;
	ans = r;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mn = min(mn, x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
	}
	if (mx > mn) ans = r % mn + r/mn*mx;
	cout << ans << "\n";
	return 0;
}
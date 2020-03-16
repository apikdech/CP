/*
 * Author: apikdech
 * Time: 21:45:26 26-06-2019
 * Last Modified: 21:47:16 26-06-2019
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin >> q;
	while(q--) {
		int n, k, mn = 1e9, mx = -1, x, ans = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> x;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		if (mx - mn > 2*k) ans = -1;
		else ans = mn + k;
		cout << ans << "\n";
	}
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}
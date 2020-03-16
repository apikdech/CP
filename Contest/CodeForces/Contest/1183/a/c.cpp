/*
 * Author: apikdech
 * Time: 22:01:32 26-06-2019
 * Last Modified: 22:07:41 26-06-2019
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
		ll k, n, a, b, ans = 0;
		cin >> k >> n >> a >> b;
		if (k <= n * b) ans = -1;
		else {
			ll l = 0, r = n;
			while(l <= r) {
				ll m = (l + r) >> 1;
				if (k <= m * a + (n-m) * b) r = m - 1;
				else l = m + 1, ans = m;
			}
		}
		cout << ans << "\n";
	}
	// cerr << "time = " << (int)(clock() * 1000. / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}
/**
 * author:  apikdech
 * created: 15.12.2019 16:16:46
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b, c, d, e, f, x = 0, ans = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for (ll i = 0; i < N; i++) {
		x = d - i;
		if (x < 0) break;
		x = min({b, c, x});
		ans = max(ans, (min(i, a) * e + x * f));
	}
	cout << ans << "\n";
	return 0;
}

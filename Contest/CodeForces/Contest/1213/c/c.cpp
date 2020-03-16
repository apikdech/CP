/*
 * Author: apikdech
 * Time: 22:17:35 30-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll n, m;

ll f(int len) {
	ll ans = 0, tmp = m;
	for (int i = 0; i < len; i++) {
		ans += tmp % 10;
		tmp += m;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		ll ans = 0, x;
		cin >> n >> m;
		x = n/m;
		ans += (x/10) * f(10);
		x = x - 10*(x/10);
		ans += f(x);
		cout << ans << "\n";
	}
	return 0;
}

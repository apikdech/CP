/**
 * author:  apikdech
 * created: 12.12.2019 20:38:06
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll calc(ll a, ll b, ll c) {
	return (abs(a-b) + abs(a-c) + abs(b-c));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		ll x[5], ans = (ll)1e18;
		cin >> x[0] >> x[1] >> x[2];
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				for (int k = -1; k <= 1; k++) {
					ans = min(ans, calc(x[0] + i, x[1] + j, x[2] + k));
				}
			}
		}
		cout << ans << "\n";

	}
	return 0;
}

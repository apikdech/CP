/**
 * author:  apikdech
 * created: 19.12.2019 22:15:03
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
		ll x, y, ans = MOD;
		cin >> x >> y;
		int ok = 0;
		ll dif = abs(x-y);
		for (ll i = 0; i <= (int)1e6; i++) {
			ll res = i * (i + 1)/2;
			if (res >= dif && (res & 1) == (dif & 1)) {
				cout << i << "\n";
				ok = 1;
				break;
			}
		}
	}
	return 0;
}

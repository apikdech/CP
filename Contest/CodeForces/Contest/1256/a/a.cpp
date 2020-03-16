/**
 * author:  apikdech
 * created: 04.11.2019 20:21:15
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		ll a, b, n, s, ok = 0;
		cin >> a >> b >> n >> s;
		if (n*a + b < s) ok = 0;
		else {
			ll l = 0, r = a, m;
			while(l <= r) {
				m = (l + r) >> 1;
				if (n * m > s) r = m - 1;
				else {
					if (n * m + b < s) l = m + 1;
					else {
						ok = 1;
						break;
					}
				}
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
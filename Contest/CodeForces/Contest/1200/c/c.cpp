/*
 * Author: apikdech
 * Time: 21:15:27 11-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m, g = 0;
	cin >> n >> m;
	int q;
	cin >> q;
	if (n % m == 0) g = m;
	else if (m % n == 0) g = n;
	else g = __gcd(n, m);
	while(q--) {
		ll sx, sy, ex, ey, ok = 0;
		cin >> sx >> sy >> ex >> ey;
		if (g == 1) ok = 1;
		if (sx == 1) {
			if (ex == 1) {
				if (((sy-1)/(n/g)) == (ey-1)/(n/g)) ok = 1;
			} else {
				if ((sy-1)/(n/g) == (ey-1)/(m/g)) ok = 1;
			}
		} else {
			if (ex == 1) {
				if (((sy-1)/(m/g)) == (ey-1)/(n/g)) ok = 1;
			} else {
				if (((sy-1)/(m/g)) == (ey-1)/(m/g)) ok = 1;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

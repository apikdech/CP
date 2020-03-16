/*
 * Author: apikdech
 * Time: 21:46:24 13-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll g;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		g = __gcd(g, x);
	}
	if (g == 1) return cout << "1\n", 0;
	for (ll i = 1; i * i <= g; i++) {
		if (g % i == 0) {
			if (g / i == i) cnt++;
			else cnt += 2;
		}
	}
	// cout << g << "\n";
	cout << cnt << "\n";
	return 0;
}

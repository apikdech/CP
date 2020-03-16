/**
 * author:  apikdech
 * created: 27.11.2019 21:33:27
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
		ll r, b, k;
		cin >> r >> b >> k;
		if (r == b) cout << "OBEY\n";
		else {
			if (r < b) swap(r, b);
			ll lcm = r / __gcd(r, b) * b;
			b = lcm / b;
			r = lcm / r;
			b--;
			ll x = (b + r - 1)/r;
			// cout << b << " " << r << " " << x << "\n";
			if (x >= k) cout << "REBEL\n";
			else cout << "OBEY\n";
		}
	}
	return 0;
}

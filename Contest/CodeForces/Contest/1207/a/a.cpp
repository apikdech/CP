/*
 * Author: apikdech
 * Time: 21:37:10 22-08-2019
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
		int b, p, f, h, c, ans = 0;
		cin >> b >> p >> f >> h >> c;
		if (h > c) {
			if (2*p <= b) ans += p * h, b -= 2*p;
			else ans += b/2 * h, b = 0;
			ans += min(b/2, f) * c;
		} else {
			if (2*f <= b) ans += f*c, b -= 2*f;
			else ans += b/2 * c, b = 0;
			ans += min(b/2, p) * h;
		}
		cout << ans << "\n";
	}
	return 0;
}

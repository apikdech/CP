/*
 * Author: apikdech
 * Time: 10:05:50 27-05-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	ll ans = 0, n = s.length();
	for (int l = 0; l < n; l++) {
		bool ok = 0;
		for (int r = l + 2; r < n; r++) {
			for (int m = r - 1; 2 * m - r >= l; m--) {
				if (s[r] == s[m] && s[m] == s[2*m - r]) {
					ok = 1;
					break;
				}
			}
			if (ok) {
				ans += n - r;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
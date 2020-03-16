/*
 * Author: apikdech
 * Time: 23:08:36 20-09-2019
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
		int c, m, x, ans = 0, tim, res;
		cin >> c >> m >> x;
		tim = min(c, m);
		res = c + m + x - 2*tim;
		if (res >= tim) cout << tim << "\n";
		else {
			int l = 1, r = tim, mid;
			res = c + m + x;
			while(l <= r) {
				mid = (l + r) >> 1;
				if (3*mid <= res) ans = mid, l = mid+1;
				else r = mid-1;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}

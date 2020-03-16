/*
 * Author: apikdech
 * Time: 21:55:01 24-07-2019
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
		int n, ax[5], ay[5], ok = 1;
		ax[0] = ay[0] = -1e5, ax[1] = ay[1] = 1e5;
		cin >> n;
		int x[n+5], y[n+5], f[n+5][5];
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i] >> f[i][1] >> f[i][2] >> f[i][3] >> f[i][4];
		}
		for (int i = 0; i < n; i++) {
			if (f[i][1] && f[i][2] && f[i][3] && f[i][4]) continue;
			if (!f[i][4]) {
				if (ay[1] < y[i]) ok = 0;
				else ay[0] = max(y[i], ay[0]);
			}
			if (!f[i][3]) {
				if (ax[0] > x[i]) ok = 0;
				else ax[1] = min(x[i], ax[1]);
			}
			if (!f[i][2]) {
				if (ay[0] > y[i]) ok = 0;
				else ay[1] = min(y[i], ay[1]);
			}
			if (!f[i][1]) {
				if (ax[1] < x[i]) ok = 0;
				else ax[0] = max(x[i], ax[0]);
			}
			if (ax[0] > ax[1] || ay[0] > ay[1]) ok = 0;
			if (!ok) break;
		}
		if (ok) cout << 1 << " " << ax[0] << " " << ay[0] << "\n";
		else cout << "0\n";
	}
	return 0;
}

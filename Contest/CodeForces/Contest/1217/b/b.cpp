/*
 * Author: apikdech
 * Time: 22:12:35 05-09-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
int n, ok;
ll x, d[N], h[N], dist[N], l, r, m, res, mdmg, md, id, idmg, tmp = 0, ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ok = 1, ans = 0, res = 0, mdmg = -1, md = -1, id = -1, idmg = -1;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> h[i];
			dist[i] = d[i] - h[i];
			if (md < d[i]) md = d[i], id = i;
			if (mdmg < dist[i]) mdmg = dist[i], idmg = i;
		}
		l = 0, r = 1e9;
		while(l <= r) {
			m = (l + r) >> 1;
			if (m * mdmg >= x - md) ans = m, r = m-1;
			else l = m+1;
		}
		// cout << ans << " ";
		if (ans * mdmg <= x) ans++;
		if (mdmg <= 0 && md < x) ok = 0;
		if (!ok) ans = -1;
		cout << ans << "\n";
	}
	return 0;
}

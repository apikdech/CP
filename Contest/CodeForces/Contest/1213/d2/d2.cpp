/*
 * Author: apikdech
 * Time: 22:42:04 30-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5, INF = 1e9;
int a[N], cnt[N], ans = INF, sz[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		int cx = 0;
		while(a[i] >= 0) {
			sz[a[i]]++;
			cnt[a[i]] += cx;
			cx++;
			if (sz[a[i]] >= k) ans = min(ans, cnt[a[i]]);
			if (a[i] == 0 && a[i]/2 == 0) break;
			a[i] /= 2;
		}
	}
	cout << ans << "\n";
	return 0;
}

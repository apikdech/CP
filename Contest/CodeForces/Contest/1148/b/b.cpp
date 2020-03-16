/*
 * Author: apikdech
 * Time: 21:56:07 01-06-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
ll a[N], b[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m, ta, tb, k, ans = 0;
	cin >> n >> m >> ta >> tb >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += ta;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	if (k >= m || k >= n) return cout << "-1\n", 0;
	int ida = 0, idb = 0;
	while(b[idb] < a[0] && idb < m) idb++;
	if (idb + k >= m) return cout << "-1\n", 0;
	ans = max(ans, b[idb + k]);
	for (int i = 0; i < k; i++) {
		int x = lower_bound(b, b+m, a[i+1]) - b;
		if (x + k - 1 - i >= m) return cout << "-1\n", 0;
		ans = max(ans, b[x+k-1-i]);
	}
	cout << ans + tb << "\n";
	return 0;
}

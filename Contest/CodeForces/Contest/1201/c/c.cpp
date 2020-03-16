/*
 * Author: apikdech
 * Time: 16:01:38 11-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;
ll a[N], n, k, sum[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
	ll l = 0, r = 1e9, m, ans = a[(n+1)/2];
	while(l <= r) {
		m = (l + r) >> 1;
		ll idx = upper_bound(a+1, a+n+1, a[(n+1)/2]+m) - a;
		idx--;
		// cout << m << " " << idx << "\n";
		if ((a[(n+1)/2]+m)*(idx-(n+1)/2+1) - sum[idx] + sum[(n+1)/2-1] <= k) l = m+1, ans = m;
		else r = m-1;
	}
	cout << a[(n+1)/2] + ans << "\n";
	return 0;
}

/*
 * Author: apikdech
 * Time: 21:25:46 14-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
ll a[N], pref[N], suff[N], ans = 0, n, k, sum = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++ ) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1] + a[i];
	}
	for (int i = n; i > 0; i--) {
		suff[i] = suff[i+1] + a[i];
	}
	int l = 1, r = n;
	while(l <= r) {
		ll tmp = l * a[l] - pref[l];
		tmp += suff[r] - (n - r + 1) * a[r];
		// cout << l << " " << r << " " << tmp << "\n";
		if (tmp <= k) l++, r--, sum = tmp;
		else {
			l--, r++;
			break;
		}
	}
	// cout << l << " " << r << "\n";
	if (l >= r) l--, r++;
	cout << max(0LL, a[r] - a[l] - (k - sum)/l) << "\n";
	return 0;
}

/*
 * Author: apikdech
 * Time: 19:47:52 11-08-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 105;
ll a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, m, k, ok = 1;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n-1; i++) {
			if (a[i] >= a[i+1]) m += min(a[i], a[i] - a[i+1] + k);
			else {
				if (a[i+1] - a[i] <= k) {
					m += min(a[i], k - a[i+1] + a[i]);
				} else if (a[i+1] - a[i] - m <= k) {
					m -= a[i+1] - a[i] - k;
				}
				else ok = 0;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

/**
 * author:  apikdech
 * created: 14.12.2019 18:20:04
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 2e5 + 5;

ll a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		map<ll, int> cnt, vis;
		ll ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		sort(a, a+n);
		for (int i = 0; i < n; i++) {
			if (vis[a[i]]) continue;
			ll res = 0;
			for (ll j = 0; j < 32; j++) {
				ll x = a[i] << j;
				if (cnt.count(x)) {
					res = j;
					vis[x] = 1;
				}
			}
			// cout << a[i] << " " << res << "\n";
			while(a[i] % 2 == 0) a[i] /= 2, ans++;
			ans += res;
		}
		cout << ans << "\n";
	}
	return 0;
}

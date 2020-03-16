/**
 * author:  apikdech
 * created: 01.11.2019 10:41:08
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, k, ans = 0;
	map<vector<pair<ll, ll>>, ll> m;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll a;
		vector<pair<ll, ll>> x, y;
		cin >> a;
		for (ll j = 2; j * j <= a; j++) {
			ll cnt = 0;
			while (a % j == 0) cnt++, a /= j;
			if (cnt % k) x.push_back({j, cnt % k});
		}
		if (a > 1) x.push_back({a, 1});
		for (auto it : x) y.push_back({it.first, k - it.second});
		ans += m[y];
		m[x]++;
	}
	cout << ans << "\n";
	return 0;
}